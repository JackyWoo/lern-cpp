//
// Created by wujianchao5 on 2020/10/29.
//
#include <iostream>
#include <climits>
#include <typeinfo>

void minMaxTest(){

    using namespace std;

    // max and size
    cout << "size of char : "  <<  sizeof(char) << endl;

    int nInt = INT_MAX;
    int nBitInt = sizeof(int);
    cout << "max int :  " << nInt << endl;
    cout << "size of int : " << nBitInt << endl;

    long nLong = LONG_MAX;
    int nBitLong = sizeof(long);
    cout << "max long " << nLong << endl;
    cout << "size of long " << nBitLong << endl;

    long long nLLong = LLONG_MAX;
    int nBitLLong = sizeof(long long);
    cout << "max of long long "  << nLLong << endl;
    cout << "size of long long " << nBitLLong << endl;

    // int default value is arbitrary
    int a;
    cout << "int default value is " << a << endl;

    string b;
    cout << b << endl;

    // unsigned type

    unsigned int ui = 0;
    unsigned char uc = 0;

    // char

    cout << "size of char16_t: " << sizeof(char16_t) << endl;
    cout << "size of char32_t: " << sizeof(char32_t) << endl;


    // 原始的array
    int yams[] = {1,2,3};

    cout << "array size " << sizeof yams / sizeof(int)<< endl;
    cout << "array out of bound " << yams[4] << endl;

    // 初始化第一个值，后续值填充0；
    int arr[3] = {1};
    cout << "array element 1 value " << arr[1] << endl;


    // 字符串
    // C-Style字符串，字符串以\0结尾，长度永远需要加1
    char dog[4] = {'d','o','g','\0'};
    char dog2[] = "dog";
    cout << "size of dog2 " << sizeof(dog2)/sizeof(char)<<endl;
    cout <<dog <<" " << dog2 <<endl;

    // 字符串拼接
    cout << "I am a "
            "good "
            "boy"<<endl;

    // c++ style字符串
    string  s1 = "abc";
    cout<<"string size "
          << sizeof(s1)
          << endl;
    s1.length();
    cout <<sizeof(s1.at(0))<<endl;

    string s2 = "a";
    string s3;
}


class Object {

};

/**
 * 判断类型是否相同
 */
void typeInfoTest(){
    using namespace std;

    //获取一个普通变量的类型信息
    int n = 100;
    const type_info &nInfo = typeid(n);
    cout<<nInfo.name()<<" | "<<nInfo.hash_code()<<endl;

    Object obj;
    Object * objPtr = new Object;
    Object * objPtr2 = new Object;

    const type_info & classInfo = typeid(Object);
    const type_info & objInfo = typeid(obj);
    const type_info & objPtrInfo = typeid(*objPtr);
    const type_info & objPtrInfo2 = typeid(*objPtr2);

    cout<<objInfo.name()<<" | "<<objInfo.hash_code()<<endl;
    cout<<objPtrInfo.name()<<" | "<<objPtrInfo.hash_code()<<endl;
    cout<<objPtrInfo2.name()<<" | "<<objPtrInfo2.hash_code()<<endl;

    cout<<(objInfo == classInfo)<<endl;
    cout<<(objInfo == objPtrInfo)<<endl;
    cout<<(classInfo == objPtrInfo)<<endl;
    cout<<(objPtrInfo2 == objPtrInfo)<<endl;
}

int main(){
    minMaxTest();
    typeInfoTest();
}