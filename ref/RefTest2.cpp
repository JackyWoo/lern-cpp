//
// Created by wujianchao5 on 2020/12/25.
//

#include <memory>
#include <iostream>
#include <type_traits>

class Foo {
public:
    Foo() { std::cout << "Foo Default constructor\n"; }
    Foo(const Foo &) { std::cout << "Foo Copy\n"; }
    Foo(Foo &&) { std::cout << "Foo Move\n"; }
};

std::aligned_storage<sizeof(Foo)> contents;
Foo &alias = *reinterpret_cast<Foo *>(&contents);

void ByVal(Foo a) {
    new(&contents) Foo(std::move(a));
    alias.~Foo();
}

void ByLCRef(Foo const &a) {
    new(&contents) Foo(a);
    alias.~Foo();
}

void ByRRef(Foo &&a) {
    new(&contents) Foo(std::move(a));
    alias.~Foo();
}

int main() {
    std::cout << "Foo a\n";
    Foo a;
    std::cout << "\n";

    std::cout << "ByVal(a);\n";
    ByVal(a);

    std::cout << "\nByVal(std::move(a));\n";
    ByVal(std::move(a));

    std::cout << "\nByVal(Foo());\n";
    ByVal(Foo());

    std::cout << "\nByLCRef(a);\n";
    ByLCRef(a);

    std::cout << "\nByRRef(std::move(a));\n";
    ByRRef(std::move(a));

    std::cout << "\nByRRef(Foo());\n";
    ByRRef(Foo());
}