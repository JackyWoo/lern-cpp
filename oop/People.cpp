//
// Created by wujianchao5 on 2021/1/4.
//

#include "People.h"

void People::show(){
    using namespace std;
    cout<<"name: " << name << ", age: " << age << endl;
}

People::String People::getName() {
    return name;
}

int People::getAge() {
    return age;
}

People::People(People::String name, int age):name(name), age(age) {

}
