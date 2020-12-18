//
// Created by wujianchao5 on 2020/12/23.
//

#include <iostream>
#include <memory>

using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex();


    Complex(double real, double imag);
    void display() const;
    /**
     * 声明为友元函数，请注意友元函数和友元类，并不是成员函数和成员类
     *
     * 但它破坏了类的封装性和隐藏性，使得非成员函数可以访问类的私有成员
     */
    friend Complex operator+(const Complex &a, const Complex &b);
};

//声明operator重载函数
Complex operator+(const Complex &a, const Complex &b);

Complex::Complex() {
    this->real = 0;
    this->imag = 0;
}

Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

void Complex::display() const {
    cout<<"real:"<<real<<", image:"<<imag<<endl;
}


Complex operator+(const Complex &a, const Complex &b) {
    Complex ret;
    ret.real = a.real + b.real;
    ret.imag = a.imag + b.imag;
    return ret;
}

int main(){
    shared_ptr<Complex> a = make_shared<Complex>(1, 1);
    shared_ptr<Complex> b = make_shared<Complex>(2, 2);
    Complex c = *a + *b;
    c.display();

    std::string s = "北京";
    cout<< sizeof(s)<<endl;
    cout<< (s)<<endl;
}