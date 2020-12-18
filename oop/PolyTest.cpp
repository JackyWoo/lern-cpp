//
// Created by wujianchao5 on 2020/12/22.
//

#include<iostream>

using namespace std;

//基类Base
class Base {
protected:
    int a;
public:
    Base();
    virtual ~Base();
    Base(int a);
    /**
     * 函数声明为virtual，则方法会覆盖，并且方法相同的判定条件是方法签名相同，而不仅仅是方法名
     */
    virtual void display();
};

Base::Base() {
    cout << "Base constructor" << endl;
}

Base::Base(int a): a(a) {
    cout << "Base constructor with args" << endl;
}

void Base::display() {
    cout << "Base::display:" << a << endl;
}

Base::~Base() {
    cout<<"destroy Base"<<endl;
}

//派生类Derived
class Derived : public Base {
private:
    int b{};
public:
    Derived();
    ~Derived() override;
    Derived(int a, int b);
    void display() override;
};

Derived::Derived() {
    cout << "Derived constructor" << endl;
}

Derived::Derived(int a, int b) : b(b) {
    Base::a = a;
    cout << "Derived constructor with args" << endl;
}

void Derived::display() {
    cout << "Derived::display:" << a << endl;
}

Derived::~Derived() {
    cout << "destroy Derived" << endl;
}

void virtualMethodTest(){
    Base * pa = new Base(1);
    Derived * pb = new Derived(2, 3);

    pa = pb;

    /**
     * 调用派生类的函数
     */
    pa->display();
}



void virtualMethodWithRefTest(){
    Base * pa = new Base(1);
    auto * pb = new Derived(2, 3);

    pa = pb;

    /**
     * 调用派生类的函数
     */
    pa->display();
}

/**
 * 当派生类中有需要释放的资源的时候，析构函数需要声明为virtual的
 */
void virtualDestructorTest(){
    Base * pa = new Derived(2, 3);
    delete pa;

    Derived * pb = new Derived(2, 3);
    delete pb;
}

void constructorTest(){
    Derived * pb = new Derived();
    delete pb;

    Derived * pc = new Derived(1, 2);
    delete pc;
}

int main(){
//    virtualMethodTest();
//    virtualDestructorTest();
    constructorTest();
}