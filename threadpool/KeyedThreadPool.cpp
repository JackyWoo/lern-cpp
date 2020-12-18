#include "KeyedThreadPool.h"
#include "getNumberOfPhysicalCPUCores.h"

#include <type_traits>


namespace DB
{
    class Exception {
    private:
        const char * msg = nullptr;
    public:
        explicit Exception(const char* msg);
        ~Exception(){
            delete msg;
        }
    };

    Exception::Exception(const char *msg) {
        msg = msg;
    }
}


//const String KEY_RANDOM = "key_random";

template <typename Thread>
KeyedThreadPoolImpl<Thread>::KeyedThreadPoolImpl()
    : KeyedThreadPoolImpl(getNumberOfPhysicalCPUCores())
{
}


template <typename Thread>
KeyedThreadPoolImpl<Thread>::KeyedThreadPoolImpl(size_t max_threads_)
    : KeyedThreadPoolImpl(max_threads_, std::min<size_t>(max_threads_, 1), 10000)
{
}

template <typename Thread>
KeyedThreadPoolImpl<Thread>::KeyedThreadPoolImpl(size_t max_threads_, size_t max_free_threads_, size_t queue_size_, bool shutdown_on_exception_)
    : max_threads(max_threads_)
    , max_free_threads(max_free_threads_)
    , queue_size(queue_size_)
    , shutdown_on_exception(shutdown_on_exception_)
{
}

template <typename Thread>
void KeyedThreadPoolImpl<Thread>::setMaxThreads(size_t value)
{
    std::lock_guard lock(mutex);
    max_threads = value;
}

template <typename Thread>
void KeyedThreadPoolImpl<Thread>::setMaxFreeThreads(size_t value)
{
    std::lock_guard lock(mutex);
    max_free_threads = value;
}

template <typename Thread>
void KeyedThreadPoolImpl<Thread>::setQueueSize(size_t value)
{
    std::lock_guard lock(mutex);
    queue_size = value;
}


template <typename Thread>
template <typename ReturnType>
ReturnType KeyedThreadPoolImpl<Thread>::scheduleImpl(Job job, String key, std::optional<uint64_t> wait_microseconds)
{
    auto on_error = [&]
    {
        if constexpr (std::is_same_v<ReturnType, void>)
        {
            if (first_exception)
            {
                std::exception_ptr exception;
                std::swap(exception, first_exception);
                std::rethrow_exception(exception);
            }
            throw DB::Exception("Cannot schedule a task");
        }
        else
            return false;
    };

    {
        std::unique_lock lock(mutex);

        auto pred = [this] { return !queue_size || scheduled_jobs < queue_size || shutdown; };

        if (wait_microseconds)  /// Check for optional. Condition is true if the optional is set and the value is zero.
        {
            if (!job_finished.wait_for(lock, std::chrono::microseconds(*wait_microseconds), pred))
                return on_error();
        }
        else
            job_finished.wait(lock, pred);

        if (shutdown)
            return on_error();

        jobs.emplace_back(std::move(job), key);
        ++scheduled_jobs;

        if (threads.size() < std::min(max_threads, scheduled_jobs))
        {
            threads.emplace_front();
            try
            {
                threads.front() = Thread([this, it = threads.begin()] { worker(it); });
            }
            catch (...)
            {
                threads.pop_front();

                /// Remove the job and return error to caller.
                /// Note that if we have allocated at least one thread, we may continue
                /// (one thread is enough to process all jobs).
                /// But this condition indicate an error nevertheless and better to refuse.

                jobs.pop_back();
                --scheduled_jobs;
                return on_error();
            }
        }
    }
    new_job_or_shutdown.notify_one();
    return ReturnType(true);
}

template <typename Thread>
void KeyedThreadPoolImpl<Thread>::scheduleOrThrowOnError(Job job, String key)
{
    scheduleImpl<void>(std::move(job), key, std::nullopt);
}

template <typename Thread>
bool KeyedThreadPoolImpl<Thread>::trySchedule(Job job, String key, uint64_t wait_microseconds) noexcept
{
    return scheduleImpl<bool>(std::move(job), key, wait_microseconds);
}

template <typename Thread>
void KeyedThreadPoolImpl<Thread>::scheduleOrThrow(Job job, String key, uint64_t wait_microseconds)
{
    scheduleImpl<void>(std::move(job), key, wait_microseconds);
}

template <typename Thread>
void KeyedThreadPoolImpl<Thread>::wait()
{
    {
        std::unique_lock lock(mutex);
        job_finished.wait(lock, [this] { return scheduled_jobs == 0; });

        if (first_exception)
        {
            std::exception_ptr exception;
            std::swap(exception, first_exception);
            std::rethrow_exception(exception);
        }
    }
}

template <typename Thread>
KeyedThreadPoolImpl<Thread>::~KeyedThreadPoolImpl()
{
    finalize();
}

template <typename Thread>
void KeyedThreadPoolImpl<Thread>::finalize()
{
    {
        std::unique_lock lock(mutex);
        shutdown = true;
    }

    new_job_or_shutdown.notify_all();

    for (auto & thread : threads)
        thread.join();

    threads.clear();
    keys_in_fly.clear();
    jobs.clear();
}

template <typename Thread>
size_t KeyedThreadPoolImpl<Thread>::active() const
{
    std::unique_lock lock(mutex);
    return scheduled_jobs;
}

template <typename Thread>
void KeyedThreadPoolImpl<Thread>::worker(typename std::list<Thread>::iterator thread_it)
{
    /// local thread

    while (true)
    {
        Job job;
        String job_key;

        bool need_shutdown = false;

        {
            std::unique_lock lock(mutex);
            new_job_or_shutdown.wait(lock, [this] { return shutdown || !jobs.empty(); });
            need_shutdown = shutdown;

            if (!jobs.empty())
            {
                /// find job
                bool find = false;
                for(auto itr = jobs.begin(); itr != jobs.end(); itr++)
                {
                    if(itr->key == DB::KEY_RANDOM || !keys_in_fly.contains(itr->key))
                    {
                        find = true;
                        job = std::move(itr->job);
                        job_key = itr->key;

                        if(itr->key != DB::KEY_RANDOM)
                        {
                            keys_in_fly.insert(itr->key);
                        }

                        jobs.erase(itr);
                        break;
                    }
                }

                if(!find)
                {
                    /// simply finish the thread
                    return;
                }

            }
            else
            {
                /// shutdown is true, simply finish the thread.
                return;
            }
        }

        if (!need_shutdown)
        {
            try
            {

                job();
                /// job should be reset before decrementing scheduled_jobs to
                /// ensure that the Job destroyed before wait() returns.
                job = {};
            }
            catch (...)
            {
                /// job should be reset before decrementing scheduled_jobs to
                /// ensure that the Job destroyed before wait() returns.
                job = {};

                {
                    std::unique_lock lock(mutex);
                    if (!first_exception)
                        first_exception = std::current_exception(); // NOLINT
                    if (shutdown_on_exception)
                        shutdown = true;
                    --scheduled_jobs;

                    /// erase key
                    keys_in_fly.erase(job_key);
                }

                job_finished.notify_all();
                new_job_or_shutdown.notify_all();
                return;
            }
        }

        {
            std::unique_lock lock(mutex);
            --scheduled_jobs;

            /// erase key
            keys_in_fly.erase(job_key);

            if (threads.size() > scheduled_jobs + max_free_threads)
            {
                thread_it->detach();
                threads.erase(thread_it);
                job_finished.notify_all();
                return;
            }
        }

        job_finished.notify_all();
    }
}

template class KeyedThreadPoolImpl<std::thread>;


