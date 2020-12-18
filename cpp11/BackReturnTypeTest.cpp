//
// Created by wujianchao5 on 2020/12/21.
//

#include <iostream>

using namespace std;

void test();

/**
 * 返回值类型后置，用于类型template返回值类型推导场景
 * 其中返回值类型decltype(t + u)是根据 (t+u)推导来的
 */
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u);


int main(){
    test();
}

void test(){
    int a = add(1, 1.0);
    cout<<a<<endl;
}

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}