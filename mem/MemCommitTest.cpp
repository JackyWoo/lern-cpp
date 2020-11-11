//
// Created by wujianchao5 on 2020/11/9.
//

#include <iostream>
#include <thread>

using namespace std;

const long TIME = 6*1000;

int main()
{
    const long tenG = 4000000;
    cout << " size of char : " << sizeof(char)<< endl;
    cout << " init char array with tenG elements"<< endl;

    // commit memory cfv
    cout << "commit memory"<< endl;
    char str[tenG];
//    cout<< str << endl;
    cout << " size of committed memory : " << sizeof(str)<< endl;

    // sleep 60s
    std::this_thread::sleep_for(chrono::milliseconds(TIME));

    // allocate memory
    for(int i=0;i<tenG;i++){
        str[i]=i;
    }

    cout << " size of allocated memory : " << sizeof(str)<< endl;

    // sleep 60s
    std::this_thread::sleep_for(chrono::milliseconds(TIME));

}