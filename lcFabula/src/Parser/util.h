#pragma once

#include<sstream>
#include<string>

template<class T>
std::string toString(const T& t)
{
    std::ostringstream str;
    str << t;
    return str.str();
}