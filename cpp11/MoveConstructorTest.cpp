//
// Created by wujianchao5 on 2020/12/21.
//

#include <iostream>

using namespace std;

class Demo {
public:
    Demo():num(new int(0)){
        cout<<"construct"<<endl;
    }
    //拷贝构造函数
    Demo(const Demo & demo): num(new int(*demo.num)){
        cout<<"copy construct!"<<endl;
    }

    //添加移动构造函数
    //通常情况下右值引用形式的参数只能接收右值，不能接收左值
    //所以临时变量才会用到移动构造函数
    Demo(Demo &&demo): num(demo.num){
        demo.num = NULL;
        cout<<"move construct!"<<endl;
    }

    //析构函数
    ~Demo(){
        cout<<"class destruct!"<<endl;
        delete num;
    }
private:
    int* num;
};

Demo getDemo(){
    return Demo();
}

int main(){
    /**
     * 使用命令可以去掉编译器优化：
     *      g++ MoveConstructorTest.cpp -o MoveConstructorTest.exe -std=c++0x -fno-elide-constructors
     *
     * 正常的执行流程：
     *      construct!                   <-- 执行 Demo()
            copy construct!              <-- 执行 return Demo()
            class destruct!              <-- 销毁 Demo() 产生的匿名对象
            copy construct!              <-- 执行 a = getDemo()
            class destruct!              <-- 销毁 getDemo() 返回的临时对象
            class destruct!              <-- 销毁 a
     *
     *
     * 中间会产生两次临时变量的开销，所以编译器进行了优化，去掉了两次临时变量的开销
     *
     */
//    Demo a = getDemo();

    /**
     * 事实上，对于程序执行过程中产生的临时对象，往往只用于传递数据（没有其它的用处），并且会很快会被销毁。
     * 因此在使用临时对象初始化新对象时，我们可以将其包含的指针成员指向的内存资源直接移给新对象所有，无需再新拷贝一份，这大大提高了初始化的执行效率。
     *
     * C++给出的答案是移动构造函数和右值引用
     */
//    Demo b = getDemo();

    /**
     * 添加move构造函数后的执行流程为：
            construct!
            move construct!
            class destruct!
            move construct!
            class destruct!
            class destruct!
     */

    /**
     * 1. 非 const 右值引用只能操作右值，
     * 2. 程序执行结果中产生的临时对象（例如函数返回值、lambda 表达式等）既无名称也无法获取其存储地址，所以属于右值
     *
     * 左值初始化同类对象只能通过拷贝构造函数完成，如果想调用移动构造函数呢？
     *      c++11引入了std::move() 函数，它可以将左值强制转换成对应的右值。
     */

    Demo c = move(getDemo());

    return 0;
}