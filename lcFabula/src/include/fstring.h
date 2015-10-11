#pragma once
#include <string>

namespace fabula
{
    class String
    {
        std::string str;

    public:
		String() {}
        String(const std::string& string) : str(string) {}
		String(const char* string) : str(string) {}
    };
}