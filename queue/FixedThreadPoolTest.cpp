//
// Created by wujianchao5 on 2020/12/23.
//

#include <iostream>
#include <memory>

#include "BlockingQueue.h"
#include "FixedThreadPool.h"


int main() {
    using FixedThreadPoolPtr = std::unique_ptr<FixedThreadPool>;
    FixedThreadPoolPtr pool(new FixedThreadPool(3));


    for (int i = 0; i < 10; i++) {

        auto print = [i] {
            std::cout <<  "task: " + std::to_string(i) << std::endl;
        };

//        pool->schedule(std::to_string(i), print);
        pool->schedule(FixedThreadPool::MARK_RANDOM, print);
    }

    pool->terminate();

    system("sleep 100");

}
