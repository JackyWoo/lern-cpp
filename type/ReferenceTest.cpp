//
// Created by wujianchao5 on 2020/11/13.
//

#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
};

/**
 * C++中struct和class默认按值传递，而不是引用，需要显示设置引用传递
 */
Person & incAge(Person &p) {
    p.age ++;
}

int main() {

    Person a = {"john", 20};
    incAge(a);

    cout<<"new age " << a.age << endl;
}