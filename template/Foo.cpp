//
// Created by wujianchao5 on 2021/1/5.
//

#include "Foo.h"

template<typename T>
void Foo<T>::show(){
    // do nothing
}

template class Foo<int>;
//std::unique_ptr<GlobalFoo> GlobalFoo::the_instance;
//
////void hello(){
////    Foo<int> foo;
////}
//void GlobalFoo::initialize() {
//    if(!the_instance){
//        the_instance.reset(new GlobalFoo());
//    }
//}
//
//GlobalFoo &GlobalFoo::instance() {
//    return *the_instance;
//}
