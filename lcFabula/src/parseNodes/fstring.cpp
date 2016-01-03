#include "fstring.h"
#include "parse_tree_visitor.h"

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            String::String() {}

			String::String(const std::string& string) : _str(string) { purifyString(); }

            String::String(const char* string) : _str(string) { purifyString(); }

			ParseNode::NodeType String::nodeType()
			{
				return NodeType::String;
			}

			std::string& String::string()
			{
				return _str;
			}

			void String::purifyString()
			{
				//Remove quotation marks:
				_str = std::string(_str.begin() + 1, _str.end() - 1);

				/* Doesn't seem to work.. Will fix later
				size_t pos;
				while ((pos = _str.find("\\\"") != std::string::npos))
					_str.replace(pos, 2, "\"");
				while ((pos = _str.find("\\\'") != std::string::npos))
					_str.replace(pos, 2, "\'");
					*/
			}
        }
    }
}