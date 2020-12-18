//
// Created by wujianchao5 on 2020/12/21.
//

#include <iostream>

using namespace std;

template <typename T>
void function(T&& t);

template <typename R>
void function2(R& r);

void function3(int && r);
void function4(const int & r);

/**
 * 左值引用调用
 */
template <typename T>
void otherDef(T & t);

/**
 * 右值引用调用
 */
template <typename T>
void otherDef(const T & t);

void test();
void test1();


int main(){
//    test();
    test1();
}

void test(){
    function(5);//5 是右值
    int  x = 1;
//    function(x);//x 是左值
}

void test1(){
    int n = 5;

    function(n);
    function(5);

    /**
     * 如果定义右值引用的函数形式
     */
    function2(n);

    /**
     * function2函数没有只定义了左值的参数列表，直接传入右值会报错
     */
//    function2(5);


    function3(5);
    function4(5);

    const int m = 1;
    // const int & r 不等价于 int && r ??
//    function3(m);
    function4(m);

    function3(reinterpret_cast<int &&>(n));
}

/**
 * 完美转发：函数模板可以将自己的参数“完美”地转发给内部调用的其它函数。所谓完美，即不仅能准确地转发参数的值，还能保证被转发参数的左、右值属性不变。
 *
 * 模板函数里的右值引用，不仅能表示右值还能表示左值
 */
template <typename T>
void function(T&& t) {
    /**
     * forward：用于实现完美转发
     */
    otherDef(forward<T>(t));
//    otherDef(t);
}

template <typename R>
void function2(R& r){
    cout << "lvalue\n";
}

/**
 * function3不是模板函数，所以这里 int && 紧紧代表右值
 * @param r
 */
void function3(int && r){
    cout << "rvalue\n";
}

/**
 */
void function4(const int & r){
    cout << "rvalue\n";
}

//重载被调用函数，查看完美转发的效果
template <typename T>
void otherDef(T & t) {
    cout << "lvalue\n";
}

template <typename T>
void otherDef(const T & t) {
    cout << "rvalue\n";
}