//
// Created by JackyWoo on 2021/3/9.
//
#include <iostream>

using namespace std;

int main()
{
    // segment fault

    // 1. dangling pointer
    char * p = NULL;
    {
        char c;
        p = &c;
    }
    // now p is dangling

    // 2. double free  signal 6: SIGABRT

    char * ppp = new char('a');
    delete ppp;
    delete ppp;

    // 3. use nullptr

    int * pp = nullptr;
    *pp = 1;

    // 4. pointer out bound

    int * a = new int[2];
    // 数组越界并不一定会segfault
    int b = a[3];
    cout << b << endl;

    // 当越界超过自己内存空间，才会发生segfault
    int c = a[100000];
    cout << c << endl;

    // 5. access readonly address
    // 字符串常量，会放到常量池中，他的值是不能改变的
    // c++11 后规范需要显示添加const标记
    char *str = "hello world";
    *str= 'H';
}
