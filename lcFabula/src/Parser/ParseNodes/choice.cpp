#include "choice.h"

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
        }
    }
}