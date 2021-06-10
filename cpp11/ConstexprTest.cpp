//
// Created by JackyWoo on 2021/3/9.
//
#include <array>
#include <iostream>
#include <string>

class Cal
{
public:
    // 定义常亮
    constexpr static std::string_view HOST = "localhost";

    constexpr static int factorial(int n) { return n <= 1 ? 1 : (n * factorial(n - 1)); }
};


int main()
{
    // 表示readonly变量
    const int a = 2;
    // 表示不可变常量，在编译器期计算
    constexpr int b = 2;

    int int_arr_a[a];
    int int_arr_b[b];

    std::array<int, a> array_a{};
    std::array<int, b> array_b{};

    array_a[1] = 1;

    std::cout << "4! = ";
    // computed at compile time
    //    constN<factorial(4)> out1;

    // disallow optimization using volatile
    volatile int k = 8;
    int n = k * 1;
    std::cout << k << "! = " << Cal::factorial(n) << '\n'; // computed at run time
}