//
// Created by wujianchao5 on 2021/1/4.
//

#include "Man.h"

Man::Man(String name, int age, String weight) : People(name, age), weight(weight) {

}

void Man::show() {
    using namespace std;
    cout << "name: " << name << ", age: " << age << ", weight: " << weight << endl;
}

People::String Man::getWeight() {
    return weight;
}
