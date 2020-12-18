//
// Created by wujianchao5 on 2020/12/23.
//

#include "student.h"

/**
 * 编译的执行流程：
 *
 * 1. 预处理，执行预处理命令，比如：#include等
 * g++ -E Main.cpp -o Main.i
 * g++ -E Student.cpp -o Student.i
 *
 * 2. 编译阶段：进行语法分析，并生成汇编指令
 *      注意此时也不包含.h文件
 * g++ -S Main.i -o Main.s
 * g++ -S Student.i -o Student.s
 *
 * 3.汇编阶段：将汇编代码生成机器指令
 * g++ -c Main.s -o Main.o
 * g++ -c Student.s -o Student.o
 *
 * 4. 链接阶段：将所有的目标文件组织成一个可以执行的二进制文件
 * g++ Main.o Student.o -o student.exe
 *
 *
 * 合并编译：
 *  g++ Main.cpp Student.cpp -o student.exe
 *
 */
int main() {
    Student *pStu = new Student;
    pStu->name = "小明";
    pStu->age = 15;
    pStu->score = 92.5f;
    pStu->say();
    delete pStu;
    return 0;
}