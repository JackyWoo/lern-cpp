//
// Created by wujianchao5 on 2020/12/21.
//
#include <iostream>

using namespace std;

class IntVector {
public:
    IntVector(int) {
        cout << "constructor" << endl;
    }

    IntVector(int a, int b) {
        cout << "constructor 222" << endl;
    }

    IntVector(const IntVector &foo) {
        cout << "copy constructor" << endl;
    }

};

IntVector func(void) {
    return {123, 1};
}

int main(void) {
    IntVector a1(123);
    //拷贝构造函数
    IntVector a2 = 123;  //error: 'Foo::Foo(const Foo &)' is private


    //初始化列表
    IntVector a4{123};
    IntVector a3 = {123};
    IntVector a5 = {123, 12};

    func();
}