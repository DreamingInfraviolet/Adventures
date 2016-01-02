#include "choice.h"
#include "header.h"
#include "destination.h"
#include "writer.h"
#include <cassert>

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
					mHeader->initiateParentBinding(this);
				if(mDestination)
					mDestination->initiateParentBinding(this);
			}

			void Choice::checkSemantics()
			{
				if (mHeader)
					mHeader->checkSemantics();
				if (mDestination)
					mDestination->checkSemantics();
			}

			void Choice::write(fabula::parsing::Writer* writer)
			{
				assert(writer);
				writer->push("choice");
				if (mHeader)
					mHeader->write(writer);
				if (mDestination)
					mDestination->write(writer);
				writer->pop();
			}
        }
    }
}