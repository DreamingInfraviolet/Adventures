#pragma once
#include "header.h"
#include "destination.h"

namespace fabula
{
    class Scene;


    class Choice
    {
        Header mHeader;
		Destination mDestination;

	public:
		Choice(const Header& header, const Destination& destination)
			: mHeader(header), mDestination(destination) {}
    };
}