//
// Created by wujianchao5 on 2020/12/16.
//

#include <iostream>
#include "../oop/Stock.h"


#include <iostream>
#include <string>

using namespace std;

using String = std::string;

class Student{
private:
    String name;
    int age;
    float score;

public:
    /**
     * 普通构造函数
     */
    Student(String name, int age, float score):name(name),age(age),score(score){
        cout<<"customized constructor was called."<<endl;
    }
    /**
     * 普通构造函数
     */
    Student(String name){
        this -> name = name;
        cout<<"customized constructor was called."<<endl;
        throw std::invalid_argument("error when constructor");
    }

    /**
     * 拷贝构造函数
     */
    Student(const Student& student);

    ~Student();


    /**
     * 重载=operator
     * 如果不重载，默认会调用拷贝构造函数
     */
    Student& operator=(const Student& student);

    void print();

};

Student::Student(const Student& student){
    this->name = student.name;
    this->age = student.age;
    this->score = student.score;
    cout<<"copy constructor was called."<<endl;
}

Student& Student::operator=(const Student& student){
    this->name = student.name;
    this->age = student.age;
    this->score = student.score;
    cout<<"operator=() was called."<<endl;
    return *this;
}


Student::~Student(){
    cout<<"destroy"<<endl;
}

void Student::print(){
    cout<<this->name<<endl;
}

void test1();
void test2();

int main() {

//    test1();

/**
 * 如果构造函数抛异常，即便外层cache，对应的析构函数也不会被调用，所以不要在构造函数中抛异常，以免资源释没有被释放。
 */
    try {
        test2();
    } catch (...) {

    }
}

void test1(){
    Student s1("ming", 20, 10);
    Student s2("chao", 20, 10);
    /**
     * 初始化操作：
     *      调用拷贝构造函数
     */
    Student s3 = s1;

    /**
     * 赋值操作：
     *      调用=运算符
     */
    s3 = s2;

    s1.print();
    s3.print();
}


void test2(){
    Student s1("ming");
}