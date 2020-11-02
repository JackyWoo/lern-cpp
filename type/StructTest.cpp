//
// Created by wujianchao5 on 2020/10/30.
//

#include <iostream>
#include "Person.h"
#include "Color.h"


using namespace std;



int main(){
    Person p = {"jacky", 20};
    cout << p.name << endl;
    p.name = "jacky woo";
    cout<< p.name<<endl;
    cout<<"Person size " << sizeof(Person)<<endl;

    // enum 实际上是int
    Color color = RED;
    cout << sizeof(color)<<endl;
    cout<< color<<endl;

    Color color1 = Color(100);
    cout << color1 << endl;

}