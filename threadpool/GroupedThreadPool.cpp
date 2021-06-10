#include "GroupedThreadPool.h"
#include <exception>
#include <iostream>

class Exception : public std::exception
{
public:
    explicit Exception(const char * what) { this->what_ = what; }
    const char * what() const noexcept override { return what_; }
    ~Exception() override { delete what_; }

private:
    char const * what_;
};

template <typename Thread>
GroupedThreadPoolImpl<Thread>::GroupedThreadPoolImpl(size_t max_threads_)
    : GroupedThreadPoolImpl(max_threads_, std::min<size_t>(max_threads_, 1), 10000)
{
}

template <typename Thread>
GroupedThreadPoolImpl<Thread>::GroupedThreadPoolImpl(
    size_t max_threads_, size_t max_free_threads_, size_t queue_size_, bool shutdown_on_exception_)
    : max_threads(max_threads_), max_free_threads(max_free_threads_), queue_size(queue_size_), shutdown_on_exception(shutdown_on_exception_)
{
}

template <typename Thread>
void GroupedThreadPoolImpl<Thread>::setMaxThreads(size_t value)
{
    std::lock_guard lock(mutex);
    max_threads = value;
}

template <typename Thread>
void GroupedThreadPoolImpl<Thread>::setMaxFreeThreads(size_t value)
{
    std::lock_guard lock(mutex);
    max_free_threads = value;
}

template <typename Thread>
void GroupedThreadPoolImpl<Thread>::setQueueSize(size_t value)
{
    std::lock_guard lock(mutex);
    queue_size = value;
}


template <typename Thread>
template <typename ReturnType>
ReturnType GroupedThreadPoolImpl<Thread>::scheduleImpl(Job job, String group, std::optional<uint64_t> wait_microseconds)
{
    auto on_error = [&] {
        if constexpr (std::is_same_v<ReturnType, void>)
        {
            if (first_exception)
            {
                std::exception_ptr exception;
                std::swap(exception, first_exception);
                std::rethrow_exception(exception);
            }
            throw Exception("Cannot schedule a task");
        }
        else
            return false;
    };

    {
        std::unique_lock lock(mutex);

        auto pred = [this] { return !queue_size || scheduled_jobs < queue_size || shutdown; };

        if (wait_microseconds) /// Check for optional. Condition is true if the optional is set and the value is zero.
        {
            if (!job_finished.wait_for(lock, std::chrono::microseconds(*wait_microseconds), pred))
                return on_error();
        }
        else
            job_finished.wait(lock, pred);

        if (shutdown)
            return on_error();

        jobs.emplace_back(std::move(job), group);
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
void GroupedThreadPoolImpl<Thread>::scheduleOrThrowOnError(Job job, String group)
{
    scheduleImpl<void>(std::move(job), group, std::nullopt);
}

template <typename Thread>
bool GroupedThreadPoolImpl<Thread>::trySchedule(Job job, String group, uint64_t wait_microseconds) noexcept
{
    return scheduleImpl<bool>(std::move(job), group, wait_microseconds);
}

template <typename Thread>
void GroupedThreadPoolImpl<Thread>::scheduleOrThrow(Job job, String group, uint64_t wait_microseconds)
{
    scheduleImpl<void>(std::move(job), group, wait_microseconds);
}

template <typename Thread>
void GroupedThreadPoolImpl<Thread>::wait()
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
GroupedThreadPoolImpl<Thread>::~GroupedThreadPoolImpl()
{
    finalize();
}

template <typename Thread>
void GroupedThreadPoolImpl<Thread>::finalize()
{
    {
        std::unique_lock lock(mutex);
        shutdown = true;
    }

    new_job_or_shutdown.notify_all();

    for (auto & thread : threads)
        thread.join();

    threads.clear();
    groups_in_fly.clear();
    jobs.clear();
}

template <typename Thread>
size_t GroupedThreadPoolImpl<Thread>::active() const
{
    std::unique_lock lock(mutex);
    return scheduled_jobs;
}

template <typename Thread>
void GroupedThreadPoolImpl<Thread>::worker(typename std::list<Thread>::iterator thread_it)
{
    while (true)
    {
        Job job;
        String job_group;

        bool need_shutdown = false;

        {
            std::unique_lock lock(mutex);
            new_job_or_shutdown.wait(lock, [this] { return shutdown || !jobs.empty(); });
            need_shutdown = shutdown;

            if (!jobs.empty())
            {
                /// find job
                bool find = false;
                for (auto itr = jobs.begin(); itr != jobs.end(); itr++)
                {
                    if (itr->group == DB::GROUP_RANDOM || !groups_in_fly.contains(itr->group))
                    {
                        find = true;
                        job = std::move(itr->job);
                        job_group = itr->group;

                        if (itr->group != DB::GROUP_RANDOM)
                        {
                            groups_in_fly.insert(itr->group);
                        }

                        jobs.erase(itr);
                        break;
                    }
                }

                if (!find)
                {
                    /// simply finish the thread
                    std::string msg = "all job groups is already on the fly, finish this thread and will schedule on another thread. current thread size " + std::to_string(threads.size());
                    std::cout << msg << std::endl;
                    thread_it->detach();
                    threads.erase(thread_it);
                    return;
                }
            }
            else
            {
                /// shutdown is true, simply finish the thread.
                std::cout << "should shutdown\n";
                return;
            }
        }

        if (!need_shutdown)
        {
            try
            {
                std::string msg = "Executing job with group " + job_group;
                //                std::cout<<msg<<std::endl;

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
                    std::cout<<"--scheduled_jobs, job error scheduled jobs "<< scheduled_jobs<<std::endl;

                    /// erase group
                    groups_in_fly.erase(job_group);
                }

                job_finished.notify_all();
                new_job_or_shutdown.notify_all();
                return;
            }
        }

        {
            std::unique_lock lock(mutex);
            --scheduled_jobs;

            /// erase group
            groups_in_fly.erase(job_group);

            if (threads.size() > scheduled_jobs + max_free_threads)
            {
                String msg = "--scheduled_jobs , thread size : " + std::to_string(threads.size()) + ",scheduled_jobs:" + std::to_string(scheduled_jobs)
                    + ",max_free_threads:" + std::to_string(max_free_threads);
                std::cout << msg<<std::endl;
                std::cout << "because thread size finish this thread"<<std::endl;
                thread_it->detach();
                threads.erase(thread_it);
                job_finished.notify_all();
                return;
            }
        }

        job_finished.notify_all();
    }
}

template class GroupedThreadPoolImpl<std::thread>;
