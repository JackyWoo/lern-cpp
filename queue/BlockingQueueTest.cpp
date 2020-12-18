//
// Created by wujianchao5 on 2020/12/15.
//

#include <iostream>
#include <string>
#include <thread>
#include <memory>
#include <vector>

#include "BlockingQueue.h"

//typedef BlockingQueue<int> Queue;
void printThreadId(const char* threadName);

void produce(BlockingQueue<int>& queue);
void consume(BlockingQueue<int>& queue);

void test();
void creatTest();

int main(){
    test();
//    creatTest();
}

void test() {
    BlockingQueue<int> queue(2);

    printThreadId("main");

    std::thread t1(produce, std::ref(queue));
//    t1.detach();
    std::thread t2(consume, std::ref(queue));
//    t2.detach();
    std::thread t3(consume, std::ref(queue));
//    t3.detach();

    std::this_thread::sleep_for(std::chrono::seconds(100));
}

void printThreadId(const char* threadName){
    std::thread::id threadId = std::this_thread::get_id();
    std::cout << threadName<< ":" << std::hex << "0x"<< threadId << std::oct << std::endl;
}

void produce(BlockingQueue<int> &queue){
    printThreadId("produce");
    const int num = 100;
    for (int i = 0; i < num; ++i){
        std::cout << "push :" + std::to_string(i) << std::endl;
        queue.push(std::move(i));
    }
}

void consume(BlockingQueue<int> &queue){
    printThreadId("consume");
    std::thread::id threadId = std::this_thread::get_id();
    while (true){
        int tmp = queue.take();
        std::cout << "take :" + std::to_string(tmp) << std::endl;
    }
}

