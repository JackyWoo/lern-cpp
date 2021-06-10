//
// Created by wujianchao5 on 2021/2/8.
//

#include <exception>
#include <iostream>
#include <string>

std::string getCurrentExceptionMessage()
{
    try
    {
        throw;
    }
    catch (const std::exception & e)
    {
        std::cout << "lala" << std::endl;
    }
}

int main()
{
    try
    {
        getCurrentExceptionMessage();
    }
    catch (...)
    {
        std::cout << "caught exception" << std::endl;
    }
}