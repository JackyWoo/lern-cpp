//
// Created by wujianchao5 on 2020/12/17.
//

#include <iostream>

using namespace std;

class IntVector
{
public:
    IntVector();

    explicit IntVector(int size);

    IntVector(IntVector const & other);

    IntVector(IntVector && other) noexcept;

    ~IntVector();

    IntVector & operator=(const IntVector & other);

    void display();

private:
    int size;
    int * data;
};

IntVector::IntVector()
{
    data = nullptr;
    size = 0;
    cout << "constructor with no argus" << endl;
}

IntVector::IntVector(int size) : size(size), data(new int[size])
{
    cout << "constructor with 1 argus" << endl;
}

/**
 * 赋值或者拷贝构造函数，通过浅拷贝的方式赋值指针字段，析构的时候回带来多次析构的问题，导致程序崩溃
 */
IntVector::~IntVector()
{
    cout << "destroy" << endl;
    if (data)
    {
        delete[] data;
        data = nullptr;
        // delete pointer后，pointer本身并不会为空
        if(data){
            cout<<"data is not null"<<endl;
        }
        else {
            cout<<"data is null" <<endl;
        };

        size = 0;
    }
}

IntVector::IntVector(IntVector const & other) : size(other.size), data(new int[size])
{
    cout << "copy constructor" << endl;
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

IntVector::IntVector(IntVector && other) noexcept
{
    cout << "move constructor" << endl;
    size = other.size;
    data = other.data;
    other.data = nullptr;
}

IntVector & IntVector::operator=(const IntVector & other)
{
    cout << "operator =" << endl;
    if (&other != this)
    {
        size = other.size;
        data = other.data;
    }
    return *this;
}

void IntVector::display()
{
    cout << size << endl;
    if (size)
        cout << data[0] << endl;
}


void valueTest(IntVector vector)
{
    cout << "valueTest argu" << endl;
}


void lRefTest(IntVector & vector)
{
    cout << "lRefTest argu" << endl;
    vector.display();
}

void rRefTest(IntVector && vector)
{
    cout << "rRefTest argu" << endl;
    vector.display();
}

void pointerTest(IntVector * vector)
{
    cout << "pointer argu" << endl;
    (*vector).display();
}

IntVector && generate(int size)
{
    return IntVector(size);
}

IntVector generate1(int size)
{
    return IntVector(size);
}

IntVector & generate2(int size)
{
    IntVector vec(size);
    return vec;
}


int main()
{
    IntVector vector(2);

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
    IntVector vector1 = vector;
    vector1 = vector;

    // 6
    //    auto * vecPtr = new IntVector(1);
    //    pointerTest(vecPtr);
    //    delete vecPtr;

    // 7 segfault
    //    IntVector&& vec1 = generate(4);
    //    vec1.display();

    // 8 ok
    //    IntVector vec2 = generate1(5);
    //    vec2.display();

    // 9 segfault
    //    IntVector vec3 = generate2(6);
    //    vec3.display();

    //    IntVector && a = static_cast<IntVector>(vector);
    //    IntVector && b = move(vector);
}