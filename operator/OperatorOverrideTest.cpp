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
    //声明为友元函数
    Complex operator+(const Complex &a);
};

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

Complex Complex::operator+(const Complex &a) {
    this->real += a.real;
    this->imag += a.imag;
    return *this;
}

int main(){
    shared_ptr<Complex> a = make_shared<Complex>(1, 1);
    shared_ptr<Complex> b = make_shared<Complex>(2, 2);
    Complex c = *a + *b;
    c.display();
}