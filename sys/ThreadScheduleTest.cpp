//
// Created by wujianchao5 on 2020/11/11.
//

#include <iostream>
#include <thread>

/**
 * 操作系统进行线程调度的一个小实验：
 *  实验目标：验证当线程没有系统调用的和内存缺页中断的情况下，跑满cpu，在次情况下线程调度不会发生，此时会阻塞整个服务器。
 */

// prototype
void task();

int main()
{

    using namespace std;

    auto threadCount = 1200;

    // create thread and run task

    thread t[threadCount];
    for(int i=0; i<threadCount; i++){
        t[i] = thread(task);
        //多少核心
        cout << "hard ware concurrency: " << t[i].hardware_concurrency() << endl;
    }

    for(auto &tt : t){
        tt.detach();
    }

    // wait sub thread end in main thread
    // done

    std::this_thread::sleep_for(chrono::seconds(600));

    return 0;

}

/**
 * no system invoking, so there is no context_switch.
 * @return
 */
void task()
{
    int i;
    while(true)
    {
        i++%INT8_MAX;
    }
}
