//
// Created by wujianchao5 on 2021/1/4.
//

#ifndef LEARN_CPP_PEOPLE_H
#define LEARN_CPP_PEOPLE_H

#include <iostream>
#include <string>

class People {

public:

    using String = std::string;

    People(String name, int age);

    virtual void show();
    String getName();
    int getAge();

protected:
    String name;
    int age;
};


#endif //LEARN_CPP_PEOPLE_H
