//
// Created by wujianchao5 on 2020/12/24.
//

#include <iostream>
#include <new>

class Tool {
private:
    int id;
public:
    Tool(int id);
    ~Tool();
    /**
     * 重载operator new，自己分配内存
     */
    void* operator new(size_t size);
};

Tool::Tool(int id) {
    std::cout<<"construct Tool"<<std::endl;
    this->id = id;
}

void *Tool::operator new(size_t size) {
    std::cout<<"Tool:new allocate memory"<<std::endl;
    return malloc(size);
}

Tool::~Tool(){
    std::cout<<"destroy Tool"<<std::endl;
}



/**
 * new后台的执行原理：
 *      Tool* a = new Tool(1);
 */
void newTest(){
    // 1. 分配内存空间
    void* raw=::operator new(sizeof(Tool));

    // 2. 通过placement new调用类的构造函数，初始化申请空间
    ::new(raw) Tool(1);

    // 3. 指针类型转换
    Tool * tool = static_cast<Tool *>(raw);

    ::delete tool;
}

void overrideOperatorNewTest(){
    Tool * a = new Tool(1);
    delete a;
}

int main(){
//    newTest();
    overrideOperatorNewTest();
}