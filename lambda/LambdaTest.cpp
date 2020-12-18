//
// Created by wujianchao5 on 2020/12/18.
//

#include<string>
#include<iostream>
#include <memory>



class Bar {
public:
    using String = std::string;

    String name;
    int age;

    Bar(String name, int age):name(name), age(age){

    }

    void print(){
        std::cout<< "name:" << name << ", age:" << age << std::endl;
    }
};

void test();

int main() {
    test();
}

void test(){
    /**
     * 定义方式：
     *      1. [capture list] (params list) -> return type {function body}
     *      2. [capture list] (params list) {function body}
     *      3. [capture list] {function body}
     */


    using BarPtr = std::shared_ptr<Bar>;
    using isYong = bool (BarPtr barPtr);
    isYong yong = [](BarPtr barPtr) -> bool { barPtr -> age < 20; };

}