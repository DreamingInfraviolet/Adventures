#pragma once

/**
  * @author Anima Seteine
  * @purpose This represents a "header", which is a title with an optional description.
  *          The description is considered optional if it is not provided, or if it's empty when trimmed.
  */

#include "fstring.h"

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            class Header
            {
                String title, description;
            public:

                /** Initialises an empty header. */
                Header();

                /** Initialises a header with s1 as title and s2 as description. */
                Header(const String& s1, const String& s2);

                /** Initialises a header from the given title. */
                Header(const String& s1);
            };
        }
    }
}