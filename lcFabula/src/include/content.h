#pragma once
#include "fstring.h"

namespace fabula
{
    class Scene;

    class Content
    {
	public:
        String head;
        String body;
        Scene* owner;

        Content() : owner(NULL) {}
    };
}