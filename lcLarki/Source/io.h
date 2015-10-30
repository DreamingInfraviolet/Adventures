#ifndef IO_H
#define IO_H
#include <string>
#include <sstream>

void Inform(const std::string& message);

void Error(const std::string& message);

void Warning(const std::string& message);

template<class T>
std::string ToString(const T& t)
{
    std::ostringstream str;
    str<<t;
    return str.str();
}

#endif // IO_H
