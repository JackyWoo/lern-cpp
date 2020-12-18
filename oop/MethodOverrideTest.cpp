//
// Created by wujianchao5 on 2020/12/22.
//

#include<iostream>

using namespace std;

//基类Base
class Base {
protected:
public:
    void func();
    void func(int);
};


void Base::func() { cout << "Base::func()" << endl; }

void Base::func(int a) { cout << "Base::func(int)" << endl; }


//派生类Derived
class Derived : public Base {
public:
    void func(char *);
    void func(bool);
};


void Derived::func(char *str) { cout << "Derived::func(char *)" << endl; }

void Derived::func(bool is) { cout << "Derived::func(bool)" << endl; }


/**
 * 派生类函数覆盖的时候，只考虑函数名，不考虑参数和返回值
 */
void methodOverrideTest() {
    Derived d;
    d.func("abc");
    d.func(true);
//    d.func();  //compile error
    d.func(10);  //调用：Derived::func(bool is)
    d.Base::func();
    d.Base::func(100);
}

int main(){
    methodOverrideTest();
}