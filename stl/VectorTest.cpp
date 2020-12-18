//
// Created by wujianchao5 on 2020/12/15.
//

#include <iostream>
#include <vector>

typedef std::vector<int> Vector;

void print(int e);
void printVector(Vector v);



int main() {
    Vector list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    printVector(list);

    list.erase(list.begin() + 1);
    printVector(list);

    list.insert(list.begin() + 1, 4);
    printVector(list);

    std::string a = "a";
    std::string b = "b";

    std::vector<std::string> list2;

    std::string c = std::move(a);
    std::cout<<a<<std::endl;
}

void print(int e){
    std::cout << e << std::endl;
}

void printVector(Vector list){
    for(int a : list){
        print(a);
    }
    std::cout << std::endl;
}