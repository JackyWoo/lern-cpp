//
// Created by wujianchao5 on 2021/1/13.
//

#include <chrono>
#include <iostream>

int main() {
    using namespace std;

    // 1970年1月1日00:00的毫秒数
    chrono::time_point<chrono::system_clock, chrono::milliseconds> tp;
    tp = chrono::time_point_cast<chrono::milliseconds>(chrono::system_clock::now());
    cout << tp.time_since_epoch().count() << endl;
}