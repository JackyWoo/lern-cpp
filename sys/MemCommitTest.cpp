//
// Created by wujianchao5 on 2020/11/9.
//

#include <iostream>
#include <thread>

/**
 * 内存commit和allocation的一个小实验
 *  何时commit：new 对象
 *  何时allocate：使用对象
 */

using namespace std;

const long TIME = 1*1000;

int main()
{
    int tenG = 2*1000*1000*1000;

    // commit memory
    char *str = new char[tenG];
//    cout<< str << endl;
    cout << " size of committed memory : " << sizeof(*str) * tenG<< endl;

    // sleep 60s
    std::this_thread::sleep_for(chrono::milliseconds(TIME));

    // allocate memory
    for(int i=0;i<tenG;i++){
        str[i]=i%INT8_MAX;
    }

    cout << " size of allocated memory : " << sizeof(*str) * tenG<< endl;

    // sleep 60s
    std::this_thread::sleep_for(chrono::milliseconds(TIME));

    delete [] str;

}