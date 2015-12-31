#pragma once

/**
  * @author Anima Seteine
  * @purpose This represents an enhanced string class that stores strings that support special Fabula formatting.
  */

#include <string>
#include "parse_node.h"


namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            class String : public ParseNode
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

				/** Returns the corresponding node type of the class. */
				virtual NodeType nodeType();

				/** Notifies all children that this is the parent, and calls bindChildren on them. */
				virtual void bindChildren();

				/** Performs semantic error detection, throwing an exception if failed. */
				virtual void checkSemantics();
            };
        }
    }
}