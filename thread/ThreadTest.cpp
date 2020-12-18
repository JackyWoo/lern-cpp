//
// Created by wujianchao5 on 2020/12/15.
//

#include <thread>
#include <iostream>
#include <stdexcept>

void throwException(){
    std::cout<<"throwException"<< std::endl;
    throw std::invalid_argument("");
}

/**
 * 如果线程挂了，整个进程也会挂
 */
int main(){
    try {
        std::thread t(throwException);
        t.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }catch(...){

    }
    std::cout<<"main"<< std::endl;
}