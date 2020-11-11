//
// Created by wujianchao5 on 2020/10/30.
//
#include <iostream>

using namespace std;

int main()
{
    // 获取变量地址
    int a = 1;
    cout << a << "'s address is " << &a<<endl;

    //
    int b = 1;
    int *bPointer = &b;

    cout << bPointer << endl;
    cout << *bPointer << endl;

    int* newBPointer = bPointer;
    *bPointer = *bPointer + 1;

    cout << *(bPointer+4) << endl;
    cout << (bPointer == newBPointer) << endl;

    int arr[4] = {1,2,3,4};


    // fellow指向的内存地址没有被赋值，虽然给fellow赋值了，但是这个值存储在哪里呢，这是不确定的。
    int* fellow;
    *fellow = 12;
    cout << *fellow << endl;

    // 运行时分配内存
    int* ps = new int;
    // 使用内存
    *ps = 1;
    // 释放内存
    delete ps;

    // 编译器分配内存
    int jugs = 1;
    int* pi = &jugs;
    // delete只能释放new分配的内存
    delete pi;


    char* str;
    cout<< *str<<endl;
}
