//
// Created by wuchi on 2020/10/17.
//

#include "Hellocpp.h"
#include <iostream>

int main(){
    int i;
    int count = 0;
    for(i=0;i<5;i++){
        count +=i;
    }

    std::cout << "" + std::to_string(i);
    std::cout << "Hello cpp!";
    return 0;
}