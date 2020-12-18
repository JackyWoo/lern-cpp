#pragma once

#include <cstdint>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>
#include <list>
#include <set>
#include <optional>


namespace DB
{
    const std::string KEY_RANDOM = "_key_random_";
}


/** Very simple thread pool similar to boost::threadpool.
  * Advantages:
  * - catches exceptions and rethrows on wait.
  * - Job with same key will be executed in scheduled order.
  *
  */
template <typename Thread>
class KeyedThreadPoolImpl
{
public:
    using Job = std::function<void()>;
    using String = std::string;

    /// default num_threads is 1
    KeyedThreadPoolImpl();

    /// default num_threads is 1
    explicit KeyedThreadPoolImpl(size_t max_threads_);

    KeyedThreadPoolImpl(size_t max_threads_, size_t max_free_threads_, size_t queue_size_, bool shutdown_on_exception_ = true);

    void scheduleOrThrowOnError(Job job, String key = DB::KEY_RANDOM);

    bool trySchedule(Job job, String key = DB::KEY_RANDOM, uint64_t wait_microseconds = 0) noexcept;

    void scheduleOrThrow(Job job, String key = DB::KEY_RANDOM, uint64_t wait_microseconds = 0);

    /// Wait for all currently active jobs to be done.
    /// You may call schedule and wait many times in arbitrary order.
    /// If any thread was throw an exception, first exception will be rethrown from this method,
    ///  and exception will be cleared.
    void wait();

    /// Waits for all threads. Doesn't rethrow exceptions (use 'wait' method to rethrow exceptions).
    /// You should not destroy object while calling schedule or wait methods from another threads.
    ~KeyedThreadPoolImpl();

    /// Returns number of running and scheduled jobs.
    size_t active() const;

    void setMaxThreads(size_t value);
    void setMaxFreeThreads(size_t value);
    void setQueueSize(size_t value);

private:

    mutable std::mutex mutex;
    std::condition_variable job_finished;
    std::condition_variable new_job_or_shutdown;

    size_t max_threads;
    size_t max_free_threads;
    size_t queue_size;

    size_t scheduled_jobs = 0;
    bool shutdown = false;
    const bool shutdown_on_exception = true;

    struct JobWithKey
    {
        Job job;
        String key;

        JobWithKey(Job job_, String key_)
            : job(job_), key(key_) {}

    };

    std::list<JobWithKey> jobs;
    std::list<Thread> threads;
    std::exception_ptr first_exception;

    std::set<String> keys_in_fly;


    template <typename ReturnType>
    ReturnType scheduleImpl(Job job, String key, std::optional<uint64_t> wait_microseconds);

    void worker(typename std::list<Thread>::iterator thread_it);

    void finalize();
};

/// ThreadPool with std::thread for threads.
using KeyedThreadPool = KeyedThreadPoolImpl<std::thread>;
