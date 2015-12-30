#pragma once
#include "header.h"
#include "destination.h"

namespace fabula
{
    class Scene;


    class Choice
    {
        Header* mHeader = nullptr;
		Destination* mDestination = nullptr;

	public:
		//Takes ownership of arguments
		Choice(Header* header, Destination* destination)
			: mHeader(header), mDestination(destination) {}

		~Choice()
		{
			delete mHeader;
			delete mDestination;
		}
    };
}