#include "header.h"
#include "writer.h"

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
				mTitle.initiateParentBinding(this);
				mDescription.initiateParentBinding(this);
			}

			void Header::checkSemantics()
			{
				mTitle.checkSemantics();
				mDescription.checkSemantics();
			}

			void Header::write(Writer& writer)
			{
				writer.push("header");
				mTitle.write(writer);
				mDescription.write(writer);
				writer.pop();
			}
        }
    }
}