#pragma once
#include "content.h"

namespace fabula
{
    class Scene;

    class Choice
    {
        Content content;
        Scene* target;
    };
}