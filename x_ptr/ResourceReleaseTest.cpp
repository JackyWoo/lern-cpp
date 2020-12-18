//
// Created by wujianchao5 on 2020/12/17.
//

#include <iostream>
#include <memory>

#include "../oop/Stock.h"

using String = std::string;

class ResourceReleaseTest {
private:
    Stock* a;
    Stock* b;

public:
    ResourceReleaseTest(){
        a = new Stock("12");
        /**
         * 如果构造函数出现异常，那么当前类的析构函数不会被调用，并且 a、b的析构函数不会被调用
         */
//        throw std::invalid_argument("throw exception");
        b = new Stock("34");
    }

    void echo(){
        std::cout<<" ResourceReleaseTest is here"<<std::endl;
    }

    ~ResourceReleaseTest(){
        std::cout<<"destroy ResourceReleaseTest"<<std::endl;
        /**
         * 如果 a、b是对象，在类被销毁的时候会同时销毁成员变量a、b,销毁的同时会调用a、b的析构函数
         * 如果a、b是指针，那么a、b需要在类中的析构函数中显示的删除
         *
         * 1. 为了解决每次都需要释放指针的问题，c++引入了只能指针，思路是将a、b封装为对象
         *
         * 那么这里会引入新的问题，如果两个对象封装了同一个兑现的指针，那么指针会被释放两次，为了解决这个问题，有两个方案：
         *      shared_ptr：引用计数
         *      unique_ptr：唯一指针引用
         *
         * 2. 假如a、b的析构函数中出现异常，那么会影响后续的资源释放，所以析构函数中需要处理异常
         */
        delete a;
        delete b;
    }
};

void invoke(){
    ResourceReleaseTest rrt;
    rrt.echo();
}

int main() {
    invoke();
}

