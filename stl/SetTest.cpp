//
// Created by wujianchao5 on 2020/12/15.
//

#include <set>
#include <iostream>

/**
 * 有序且去重
 */
typedef std::set<int> Set;

int main(){

    Set set = {1, 2, 3};

    set.emplace(1);
    std::cout<< "size : " << set.size() << "\n max size: " <<set.max_size() << std::endl;



}