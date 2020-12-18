//
// Created by wujianchao5 on 2020/12/16.
//

#include <iostream>
#include "../oop/Stock.h"
#include <memory>


void invoke(Stock s);
void invokeByRef(Stock& s);


template <typename T>
class Ptr: public std::shared_ptr<T> {

};

int main(){
    Stock s1("jd");
    // 调用拷贝构造函数

    Stock s2 = s1;
    // 调用拷贝构造函数
    try {
        invoke(s1);
    } catch (...) {

    }

    Stock& s3 = s1;
    // 不会调用拷贝构造函数
    invokeByRef(s1);
    // 对引用的改变会反馈到原对象
    std::cout<<s1.getCompany() << std::endl;
    std::cout<<s3.getCompany() << std::endl;
}

void invoke(Stock s){
    Stock s4 ("tt");
    /**
     *
     * 如果抛异常，异常直接导致程序异常退出，那么对应链条上的栈对象将不会被释放
     * 如果上层调用方catch异常，那么对应的析构函数将会被调用
     */
    throw std::invalid_argument("destroy stock failed");
}

void invokeByRef(Stock& s){
    s.setCompany(s.getCompany() + "_lalal");
}