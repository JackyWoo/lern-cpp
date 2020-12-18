//
// Created by wujianchao5 on 2020/12/15.
//

#ifndef LEARN_CPP_BLOCKINGQUEUE_H
#define LEARN_CPP_BLOCKINGQUEUE_H

#include <list>
#include <mutex>
#include <climits>
#include <iostream>
#include <condition_variable>

/**
 * bounded blocking queue implemented by mutex
 * @tparam T
 */
template<typename T>
class BlockingQueue
{

public:
    explicit BlockingQueue(int maxSize = INT32_MAX);

    T take();

    void push(T&& e);

    bool isEmpty();

private:
    int maxSize;
    std::list<T> queue;

    std::recursive_mutex mutex;

    std::condition_variable_any canTake;
    std::condition_variable_any canPush;

    bool isFull();
};

template <typename T>
BlockingQueue<T>::BlockingQueue(int maxSize)
{
    this->maxSize = maxSize;
}

template <typename T>
void BlockingQueue<T>::push(T&& e)
{
    std::lock_guard<std::recursive_mutex> lock(mutex);

    while(isFull())
    {
        canPush.wait(mutex);
    }

    //push
    queue.push_back(e);
    // notify waiters
    canTake.notify_all();
}


template <typename T>
T BlockingQueue<T>::take()
{
    std::lock_guard<std::recursive_mutex> lock(mutex);

    while (isEmpty())
    {
        canTake.wait(mutex);
    }

    // take
    T e = *queue.cbegin();
    queue.erase(queue.cbegin());

    // notify waiters
    canPush.notify_all();
    return std::move(e);
}

template<typename T>
bool BlockingQueue<T>::isEmpty()
{
    std::lock_guard<std::recursive_mutex> lock(mutex);
    return queue.size() == 0;
}

template<typename T>
bool BlockingQueue<T>::isFull()
{
    std::lock_guard<std::recursive_mutex> lock(mutex);
    return queue.size() == maxSize;
}

#endif //LEARN_CPP_BLOCKINGQUEUE_H
