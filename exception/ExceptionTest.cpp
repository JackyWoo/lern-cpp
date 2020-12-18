//
// Created by wujianchao5 on 2020/12/23.
//

#include <iostream>
#include <string>
#include <exception>
#include <utility>


class MyException: public std::exception{
private:
    const char* msg;
public:
    explicit MyException(const char* msg):msg(msg) {

    }

    virtual const char* what(){
        return msg;
    }
};

void stringTest(){
    try{
        throw "string exception";
    } catch (std::string ex) {
        /**
         * const char* 类型的异常不能用string catch
         */
        std::cout<<"std::string :"<<ex<<std::endl;
    }
//    catch (const char* ex) {
//        std::cout<<ex<<std::endl;
//    }
}

void exceptionTest(){

    try{
        throw MyException("error lala");
    } catch (MyException & e) {
        std::cout<<e.what()<<std::endl;
    }
}

int main(){
    stringTest();
//    exceptionTest();
}