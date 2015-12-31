#include "choice.h"
#include "header.h"
#include "destination.h"

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            Choice::Choice(Header* header, Destination* destination)
                    : mHeader(header), mDestination(destination) {}

            Choice::~Choice()
            {
                delete mHeader;
                delete mDestination;
            }

			ParseNode::NodeType Choice::nodeType()
			{
				return NodeType::Choice;
			}

			void Choice::bindChildren()
			{
				if(mHeader)
					mHeader->bindParent(this);
				if(mDestination)
					mDestination->bindParent(this);
			}

			void Choice::checkSemantics()
			{
			}
        }
    }
}