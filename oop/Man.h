//
// Created by wujianchao5 on 2021/1/4.
//

#ifndef LEARN_CPP_MAN_H
#define LEARN_CPP_MAN_H

#include "People.h"

class Man : public People {
public:
    Man(String name, int age, String weight);

    String getWeight();
    virtual void show();
    void foo(String a);

protected:
    String weight;
};


#endif //LEARN_CPP_MAN_H
