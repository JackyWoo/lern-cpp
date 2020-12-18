//
// Created by wujianchao5 on 2020/12/31.
//

#include <iostream>
#include <map>
#include <set>
#include <mutex>
#include <chrono>
#include <random>
#include "KeyedThreadPool.h"


struct TaskWithExecutionTime {
    int task_id;
    long time;

    /// min heap
    bool operator<(const TaskWithExecutionTime &other) const { return time > other.time; }
};

using ThreadMap = std::map<std::thread::id, std::set<int>>;

void print(ThreadMap &map);

void print(std::priority_queue<TaskWithExecutionTime> &orderedTasks);

int main() {

    const int task_size = 100;
    const int task_key_size = 10;
    const int thread_pool_size = 3;

    KeyedThreadPool pool(thread_pool_size, thread_pool_size, 100);

    using namespace std;
    using MicroTime = chrono::time_point<chrono::system_clock, chrono::microseconds>;

    std::mutex mutex;
    /// keep tasks in execution order
    priority_queue<TaskWithExecutionTime> orderedTasks;

    /// step 1: schedule tasks

    const long start_time = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now()).time_since_epoch().count();

    for (int task_id = 0; task_id < task_size; task_id++) {
        pool.scheduleOrThrow(
                [&pool, start_time, task_id, &mutex, &orderedTasks] {
                    /// task start time
                    MicroTime tp = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
                    long now = tp.time_since_epoch().count();

                    /// sleep random time to mock task execution
                    static std::default_random_engine generator;
                    static std::uniform_int_distribution<int> distribution(0, 100 * 1000);
//                    auto dice = [&distribution, &generator] { return distribution(generator); };
                    static auto dice = bind(distribution, generator);
                    std::this_thread::sleep_for(std::chrono::microseconds(dice()));

                    /// record task execution order
                    {
                        std::lock_guard lock(mutex);
                        orderedTasks.push({task_id,  now - start_time});
                    }
                },
                to_string(task_id % task_key_size));
    }

    /// wait task done
    pool.wait();


    /// step 2: checking task execution order that tasks with the same key(task_id % task_key_size) must be executed in order

    bool task_executed_in_order = true;

//    /// <bucket_num, previous_task_id>
//    std::map<int, int> keyed_last_task;
//    while (!orderedTasks.empty()) {
//        TaskWithExecutionTime tmp = orderedTasks.top();
//        int key_bucket_num = tmp.task_id % task_key_size;
//
//        if (keyed_last_task.contains(key_bucket_num)) {
//            if (keyed_last_task.find(key_bucket_num)->second > tmp.task_id) {
//                task_executed_in_order = false;
//                break;
//            }
//
//            keyed_last_task.emplace(key_bucket_num, tmp.task_id);
//        } else {
//            keyed_last_task.emplace(key_bucket_num, tmp.task_id);
//        }
//
//        orderedTasks.pop();
//    }

    cout << task_executed_in_order << endl;
    print(orderedTasks);
}

void print(ThreadMap &map) {
    std::cout << std::endl;
    // print map
    for (auto itr = map.begin(); itr != map.end(); itr++) {
        std::cout << itr->first << ":\t";
        for (auto itr1 = itr->second.begin(); itr1 != itr->second.end(); itr1++) {
            std::cout << *itr1 << "\t";
        }
        std::cout << std::endl;
    }
}

void print(std::priority_queue<TaskWithExecutionTime> &orderedTasks) {
    std::cout << "Task Execution order : " << std::endl;

    while (!orderedTasks.empty()) {
        auto ele = orderedTasks.top();
        std::cout << ele.task_id << ":" << ele.time << "\t";
        orderedTasks.pop();
    }
}
