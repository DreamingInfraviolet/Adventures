#pragma once
#include "fstring.h"

namespace fabula
{
    class Header
    {
        String title, description;
    public:

		Header() {}

        Header(const String& s1, const String& s2)
            : title(s1), description(s2) {}

        Header(const String& s1)
            : title(s1) {}
    };
}

