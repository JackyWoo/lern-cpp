//
// Created by wujianchao5 on 2020/12/23.
//

#include <iostream>

void nullPtrTest(){
    char* s = nullptr;
    char* s1 = NULL;
//    std::cout<< *s<<std::endl;
//    std::cout<< *s1<<std::endl;

    printf("%s\\n",*s);
    printf("%s\\n",*s1);
}

/**
 * print 空指针会报错
 * @return
 */
int main(){
    nullPtrTest();
}