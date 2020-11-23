//
// Created by wujianchao5 on 2020/11/13.
//

#include <iostream>


// ----------------------------函数指针----------------------------------- //

int plus(int a, int b){
    return a + b;
}

int minus(int a, int b){
    return a + b;
}

int calculate(int (*pf) (int, int), int a, int b){
    return pf(a, b);
}

int functionPointer(){
    //函数指针
    int (*pf) (int, int );
    pf = plus;

    // 调用函数指针
    int r = pf(1, 2);
    std::cout << r << std::endl;

    // 函数指针作为参数
    int r1 = calculate(plus, 1, 3);
    std::cout << r1 << std::endl;

    // 创建类型别名
    typedef int (*Fun1) (int, int);
    Fun1 fun1 = plus;
    fun1(1, 3);
}


// ------------------------------inline--------------------------------- //

/**
 * 函数调用会产生一个栈帧，栈帧切换是有开销的，基于性能考虑，C++提出了inline函数。编译器将inline函数嵌入导了调用方里。
 * 但是这样做使得编译后的代码量增加了。
 *
 * 内联和宏
 *  inline是C中宏的演进特性。C中使用#define来提供宏，但是宏背后的原理字符串替换，其中X为参数的符号标记。
 *      #define SQUARE(X) X*X
 *      a = SQUARE(5); is replaced by a = 5*5
 *      a = SQUARE(5+1); is replaced by a = 5+1 * 5+1
 *
 * C++中，使用inline函数替换宏。
 */
inline double square(double x) {
    return x *x ;
}
int inlineFunction(){
    std::cout << square(2) << std::endl;
}

// ------------------------------默认参数--------------------------------- //

std::string left(std::string &s, int n = 1){
    return s.substr(0, n);
}

int defaultArgFunction() {
    std::string s = "abc";
    std::cout << left(s, 2) << std::endl;
    std::cout << left(s) << std::endl;
}

// ------------------------------泛型--------------------------------- //

template<typename T>
void cal(T a, T b) {
    a + b;
}

void templateTest(){
    cal(1, 2);
}

int main()
{
//    functionPointer();
//    inlineFunction();
    defaultArgFunction();
}