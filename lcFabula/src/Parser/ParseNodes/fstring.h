#pragma once

/**
  * @author Anima Seteine
  * @purpose This represents an enhanced string class that stores strings that support special Fabula formatting.
  */

#include <string>


namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            class String
            {
                std::string _str;

            public:
                /** Constructs the empty string. */
        		String();

                /** Constructs the string from a std::string. */
                String(const std::string& string);

                /** Constructs the string from a character pointer. */
        		String(const char* string);

                /** Returns the internal std::string object. */
        		const std::string& str() const;
            };
        }
    }
}