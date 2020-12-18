//
// Created by wujianchao5 on 2020/12/15.
//

#ifndef LEARN_CPP_FIXEDTHREADPOOL_H
#define LEARN_CPP_FIXEDTHREADPOOL_H

#include <thread>
#include <vector>
#include <memory>
#include <functional>

#include "BlockingQueue.h"

class FixedThreadPool
{

public:

    using String = std::string;
    using Job = std::function<void()>;

    using ThreadPtr = std::shared_ptr<std::thread>;
    using JobQueuePtr = std::shared_ptr<BlockingQueue<Job>>;

    const static String MARK_RANDOM;

    explicit FixedThreadPool(int size);
    ~FixedThreadPool();

    /**
     * hash(key) % size to identify thread
     * @param key
     */
    void schedule(const String& key, Job job);
    void terminate();

private:
    int size = 0;
    volatile int stopped = false;

    std::vector<ThreadPtr> pool;
    std::vector<JobQueuePtr> jobQueues;
};


#endif //LEARN_CPP_FIXEDTHREADPOOL_H
