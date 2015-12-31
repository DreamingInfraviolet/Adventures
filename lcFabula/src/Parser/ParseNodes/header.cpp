#include "header.h"

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            Header::Header() {}

            Header::Header(const String& s1, const String& s2)
                : title(s1), description(s2) {}

            Header::Header(const String& s1)
                : title(s1) {}
        }
    }
}