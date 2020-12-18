//
// Created by wujianchao5 on 2020/12/15.
//

#include <map>
#include <iostream>

/**
 * 红黑树map
 */
typedef std::map<int, int> Map;

void printMap(Map map);
void print(Map::iterator start, Map::iterator end);

int main(){

    Map map = {{1, 1}, {2, 2}};
    printMap(map);

    map.insert({3, 3});
    printMap(map);

    map.insert({2, 3});
    printMap(map);

    map.erase(1);
    printMap(map);

    //与insert功能一样，但是它可可以不用穿pair对象，而是传pair构造函数需要的参数对象即可
    //这里利用了c++11新特性：变参模板  和 完美转发
    map.emplace(4, 4);
    printMap(map);

    Map::iterator lower = map.lower_bound(3);
    print(lower, map.end());

    Map::iterator upper = map.upper_bound(3);
    print(map.begin(), upper);

}

void printMap(Map map){
    for(std::pair<int, int> p : map){
        std::cout << p.first << "\t" << p.second << std::endl;
    }
    std::cout << std::endl;
}

void print(Map::iterator start, Map::iterator end){
    for(; start!=end; start ++){
        std::cout << start->first << "\t" << start->second << std::endl;
    }
    std::cout << std::endl;
}
