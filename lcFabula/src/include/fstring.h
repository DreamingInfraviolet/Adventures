#pragma once
#include <string>

namespace fabula
{
    class String
    {
        std::string _str;

    public:
		String() {}
        String(const std::string& string) : _str(string) {}
		String(const char* string) : _str(string) {}

		std::string& str() { return _str; }
    };
}