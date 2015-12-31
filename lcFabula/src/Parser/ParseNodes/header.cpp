#include "header.h"

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            Header::Header() {}

            Header::Header(const String& s1, const String& s2)
                : mTitle(s1), mDescription(s2) {}

            Header::Header(const String& s1)
                : mTitle(s1) {}

			ParseNode::NodeType Header::nodeType()
			{
				return NodeType::Header;
			}

			void Header::bindChildren()
			{
				mTitle.bindParent(this);
				mDescription.bindParent(this);
			}

			void Header::checkSemantics()
			{
			}
        }
    }
}