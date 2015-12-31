#include "fstring.h"

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            String::String() {}

            String::String(const std::string& string) : _str(string) {}

            String::String(const char* string) : _str(string) {}

            const std::string& String::str() const { return _str; }

			ParseNode::NodeType String::nodeType()
			{
				return NodeType::String;
			}

			void String::bindChildren()
			{
			}

			void String::checkSemantics()
			{
			}
        }
    }
}