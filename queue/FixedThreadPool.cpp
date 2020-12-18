//
// Created by wujianchao5 on 2020/12/15.
//

#include "FixedThreadPool.h"


const std::string FixedThreadPool::MARK_RANDOM = "_mark_random";

FixedThreadPool::FixedThreadPool(const int size) : size(size)
{
    if (size < 1)
    {
        throw std::invalid_argument("ddl pool size must not be lower than 1");
    }

    for (int i = 0; i < size; i++)
    {
        // init jobQueues
        jobQueues.push_back(std::make_shared<BlockingQueue<Job>>(100000));
        // init pool
        pool.push_back(std::make_shared<std::thread>([this, i] {
            while (!stopped)
            {
                try
                {
                    Job job = jobQueues[i]->take();
                    job();
                } catch (...)
                {
                    //TODO ignore exception
                }
            }
        }));
    }
}

void FixedThreadPool::schedule(const String &key, Job job)
{
    // calculate thread
    size_t threadNum;
    if(MARK_RANDOM == key)
    {
        threadNum = random() % size;
    }
    else
    {
        std::hash<String> hashFun;
        threadNum = hashFun(key) % size;
    }

    // ddd to thread task queue
    jobQueues[threadNum]->push(std::move(job));
}

void FixedThreadPool::terminate()
{
    stopped = true;
}

FixedThreadPool::~FixedThreadPool()
{
    // TODO interrupt blocking queue waiting
    stopped = true;
}

