#include "choice.h"
#include "header.h"
#include "destination.h"
#include <cassert>
#include "parse_tree_visitor.h"

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

			Header& Choice::header()
			{
				assert(mHeader);
				return *mHeader;
			}

			Destination& Choice::destination()
			{
				assert(mDestination);
				return *mDestination;
			}
        }
    }
}