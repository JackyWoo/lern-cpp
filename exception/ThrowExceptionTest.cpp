//
// Created by wujianchao5 on 2021/2/8.
//

#include <exception>
#include <string>
#include <iostream>

std::string getCurrentExceptionMessage(bool with_stacktrace)
{
    try
    {
        throw;
    }
    catch (const std::exception & e)
    {
        std::out << <<std::endl;
    }
}