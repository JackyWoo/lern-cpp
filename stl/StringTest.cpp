//
// Created by wujianchao5 on 2020/12/15.
//

#include <iostream>
#include <string>

typedef  std::string String;

void println();


int main() {
    String a = "123";

    // 遍历
    for(char e : a){
        std::cout << e << std::endl;
    }

    println();

    // 遍历
    for(int i=0; i<a.size(); i++){
        std::cout<<a[i]<<std::endl;
        std::cout<<a.at(i)<<std::endl;
    }

    println();


    // 遍历
    for(String::iterator itr = a.begin(); itr != a.end(); itr++){
        std::cout << *itr << std::endl;
    }
    println();

    // 常量迭代器
    for (String::const_iterator it = a.begin(); it != a.end(); it++){
        std::cout << *it << std::endl;
    }

    println();

    // 查找
    a.find("23");

    std::cout << a.assign(2, '4') << std::endl;

}

void println(){
    std::cout << std::endl;
}