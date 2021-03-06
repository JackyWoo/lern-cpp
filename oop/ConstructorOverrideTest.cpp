//
// Created by wujianchao5 on 2020/12/22.
//

#include<iostream>

using namespace std;

//基类People
class People {
protected:
    char *m_name;
    int m_age;
public:
    People(char *, int);
    ~People();
};

People::People(char *name, int age) : m_name(name), m_age(age) {
    cout<<"construct People\n";
}

People::~People() {
    cout<<"destruct People\n";
}

//派生类Student
class Student : public People {
private:
    float m_score;
public:
    Student(char *name, int age, float score);
    ~Student();
    void display();
};

//People(name, age)就是调用基类的构造函数
Student::Student(char *name, int age, float score) : People(name, age), m_score(score) {
    cout<<"construct Student\n";
}

Student::~Student() {
    cout<<"destruct Student\n";
}

void Student::display() {
    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << "。" << endl;
}

int main() {
    Student stu("小明", 16, 90.5);
    stu.display();
    return 0;
}