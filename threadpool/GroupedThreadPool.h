#pragma once

#include <condition_variable>
#include <cstdint>
#include <functional>
#include <list>
#include <mutex>
#include <optional>
#include <queue>
#include <set>
#include <thread>
#include <string>
#include <string_view>


namespace DB
{
    const std::string GROUP_RANDOM = "_group_random_";
}


/** Very simple thread pool similar to boost::ThreadPool.
  * Advantages:
  * - Job with same group will be executed in order.
  *
  */
template <typename Thread>
class GroupedThreadPoolImpl
{
public:
    using Job = std::function<void()>;
    using String = std::string;

    /// default num_threads is 1
    GroupedThreadPoolImpl();

    /// default num_threads is 1
    explicit GroupedThreadPoolImpl(size_t max_threads_);

    GroupedThreadPoolImpl(size_t max_threads_, size_t max_free_threads_, size_t queue_size_, bool shutdown_on_exception_ = true);

    void scheduleOrThrowOnError(Job job, String group = DB::GROUP_RANDOM);

    bool trySchedule(Job job, String group = DB::GROUP_RANDOM, uint64_t wait_microseconds = 0) noexcept;

    void scheduleOrThrow(Job job, String group = DB::GROUP_RANDOM, uint64_t wait_microseconds = 0);

    /// Wait for all currently active jobs to be done.
    /// You may call schedule and wait many times in arbitrary order.
    /// If any thread was throw an exception, first exception will be rethrown from this method,
    ///  and exception will be cleared.
    void wait();

    /// Waits for all threads. Doesn't rethrow exceptions (use 'wait' method to rethrow exceptions).
    /// You should not destroy object while calling schedule or wait methods from another threads.
    ~GroupedThreadPoolImpl();

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

    struct JobWithGroup
    {
        Job job;
        String group;

        JobWithGroup(Job job_, String group_) : job(job_), group(group_) { }
    };

    std::list<JobWithGroup> jobs;
    std::list<Thread> threads;
    std::exception_ptr first_exception;

    std::set<String> groups_in_fly;


    template <typename ReturnType>
    ReturnType scheduleImpl(Job job, String group, std::optional<uint64_t> wait_microseconds);

    void worker(typename std::list<Thread>::iterator thread_it);

    void finalize();
};

/// ThreadPool with std::thread for threads.
using GroupedThreadPool = GroupedThreadPoolImpl<std::thread>;
