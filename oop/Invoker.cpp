//
// Created by wujianchao5 on 2020/11/13.
//

#include <iostream>
#include "Stock.h"

int main(){
    // init object
    // 分配在栈上
    Stock stock;
    Stock stock1("O", 100, 100, 10000);
    Stock stock2 = Stock("O", 100, 100, 10000);
    // 分配在堆上
    // stock3是指针
    Stock *stock3 = new Stock("J", 1, 1, 1);

    stock1.show();
    stock3->show();
//    stock3.show(); // 错误的使用方式
    // invoke delete
    delete stock3;


    // const变量要求
    // 1. 引用不能赋新值
    // 2. 引用的方法不能修改对象本身
    const Stock stock4("T", 1, 3, 3);


    // 创建一个数组，数组分配在栈上
    // 并且其大小为5*sizeof(Stock)
    Stock stockArr[5];
    std::cout << (sizeof(stockArr)) << std::endl;

}