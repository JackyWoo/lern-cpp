//
// Created by wujianchao5 on 2020/12/17.
//

#include <iostream>

using namespace std;

class IntVector {
public:
    IntVector();

    explicit IntVector(int size);

    IntVector(IntVector const &other);

    IntVector(IntVector &&other) noexcept;

    ~IntVector();

    IntVector const &operator=(IntVector &foo);

    void display();

private:
    int size;
    int *data;
};

IntVector::IntVector() {
    cout << "constructor with no argus" << endl;
}

IntVector::IntVector(int size) : size(size), data(new int[size]) {
    cout << "constructor with 1 argus" << endl;
}

IntVector::~IntVector() {
    cout << "destroy" << endl;
    if (data) {
        delete[] data;
        size = 0;
    }
}

IntVector::IntVector(IntVector const &other) : size(other.size), data(new int[size]) {
    cout << "copy constructor" << endl;
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

IntVector::IntVector(IntVector &&other) noexcept {
    cout << "move constructor" << endl;
    size = other.size;
    data = other.data;
    other.data = nullptr;
}

IntVector const &IntVector::operator=(IntVector &other) {
    cout << "operator =" << endl;
    size = other.size;
    data = other.data;
    other.data = nullptr;
    return *this;
}

void IntVector::display() {
    cout<<size<<endl;
    if(size)
        cout<<data[0]<<endl;
}


void valueTest(IntVector vector) {
    cout << "valueTest argu" << endl;
}


void lRefTest(IntVector & vector) {
    cout << "lRefTest argu" << endl;
    vector.display();
}

void rRefTest(IntVector && vector) {
    cout << "rRefTest argu" << endl;
    vector.display();
}

void pointerTest(IntVector * vector) {
    cout << "pointer argu" << endl;
    (*vector).display();
}

IntVector&& generate(int size){
    return IntVector(size);
}

IntVector generate1(int size){
    return IntVector(size);
}

IntVector& generate2(int size){
    IntVector vec(size);
    return vec;
}


int main() {
//    IntVector vector(2);

    // 1
//    valueTest(vector);

    // 2
//    lRefTest(vector);

    // 3
//    rRefTest(move(vector));
//    rRefTest(IntVector(3));

    // 4
//    IntVector vector1;
//    vector1 = vector;
//    vector1.display();

    // 5
//    IntVector vector1 = vector;

    // 6
//    auto * vecPtr = new IntVector(1);
//    pointerTest(vecPtr);
//    delete vecPtr;

    // 7 segfault
    IntVector&& vec1 = generate(4);
    vec1.display();

    // 8 ok
//    IntVector vec2 = generate1(5);
//    vec2.display();

    // 9 segfault
    IntVector vec3 = generate2(6);
    vec3.display();

//    IntVector && a = static_cast<IntVector>(vector);
//    IntVector && b = move(vector);

}