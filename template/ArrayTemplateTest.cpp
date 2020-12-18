//
// Created by wujianchao5 on 2020/12/23.
//

#include <iostream>

// 1：交换基本类型的值
template<class T> void swap(T & a, T & b);

// 2：交换基本类型的值
template<typename T> void swap(T & a, T & b);

// 3：交换数组类型的值
//当数组传入函数后，会转变为指针，而指针计算不出sizeof的值，所以需要在参数中传入数组的长度
template<typename T> void swap(T a[], T b[], int len){
    T temp;
    for(int i=0; i<len; i++){
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

// 4：交换数组类型的值
// cpp模板中支持非类型的参数
template<typename T, unsigned N> void swap(T (&a)[N], T (&b) [N]){
    std::cout << "array length is " << N <<std::endl;
    int arrLen = sizeof(a)/sizeof(T);
    std::cout << "array length is " << arrLen <<std::endl;

    T temp;
    for(int i=0; i<N; i++){
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int main(){
    int a[] = {1, 2, 3};
    int b[] = {3, 4, 5};
    swap(a, b);
}