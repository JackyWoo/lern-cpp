//
// Created by wujianchao5 on 2020/11/9.
//

#include <iostream>
#include <array>


using namespace std;

int main(){
    int arr[10] = {1};
    cout <<  sizeof(arr) << endl;


    int* arrNew = new int[10]{1};
    cout <<  sizeof(arrNew) << endl;
    cout <<  sizeof(*arrNew) << endl;
    cout << arrNew[0] << endl;


    // arrNew 是指向数组第一个元素的指针
    arrNew[0] = 1;
    arrNew[1] = 2;
    arrNew[2] = 3;

    // CPP中数组的操作都是有指针来进行的。
    // 此处将arrNew指向数组的第二个元素
    // 注意这里+1的单位不是一个byte，而是int
    arrNew = arrNew + 1;
    cout << arrNew[0] << endl;

    //delete arrNew;此时将arrNew重新指向第一个元素，以释放内存
    arrNew -= 1;
    delete [] arrNew;

    int length = 2;
    int* arrN = new int[length];

    cout << "--------------------" << endl;
    // 遍历数组
    int len = sizeof(arrN)/sizeof(int);
    for(int i=0;i<len;i++){
        arrN[i] = i + 10;
    }

    //第二种方式遍历数组
    for(int i=0;i<len;i++){
        cout << *arrN << endl;
        cout << arrN << endl;
        arrN += 1;
    }


    // 指针相减；
    int* a = &arrN[0];
    int* b = &arrN[1];
    cout <<"数组指针相减 " << (b-a) << endl;

    arrN -= len;
    delete []arrN;


    // ------------- 模板类array

    using namespace std;
    array<int, 5> array1;
    array<int, 5> array2 = {1,2,3,4,5};

    for(int i=0;i<array1.size();i++){
        array1[i] = i;
    }



}