//
// Created by wujianchao5 on 2020/12/17.
//

#include<string>
#include<iostream>

class Foo{

public:
    using String = std::string;

    Foo(int size) {
        std::cout << " the size is " << size << std::endl;
    }

    explicit Foo(String& str) {
        std::cout << " the string is " << str << std::endl;
    }
};

int main() {
    Foo e1(1);
    /**
     * 当类有单参构造函数的时候，初始化时可以隐士调用
     */
    Foo e2 = 1;
    /**
     * 单参构造函数explicit声明时，不可以隐士调用
     */
//    Foo e3 = "";

}

