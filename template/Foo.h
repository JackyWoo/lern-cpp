//
// Created by wujianchao5 on 2021/1/5.
//

#ifndef LEARN_CPP_FOO_H
#define LEARN_CPP_FOO_H

#include <memory>

template<typename T>
class Foo {

public:
    void show();
};

//template<typename T>
//void Foo<T>::show(){
//    // do nothing
//}

//class GlobalFoo : public Foo<int> {
//    static std::unique_ptr<GlobalFoo> the_instance;
//
//public:
//    static void initialize();
//    static GlobalFoo & instance();
//};
//
//using CFoo = Foo<int>;

#endif //LEARN_CPP_FOO_H
