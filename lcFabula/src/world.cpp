#include "world.h"
#include "section.h"
#include "parser.h"

namespace fabula
{
	World::World()
	{
		root = new Section();
	}

	World::World(Section* root)
	{
		this->root = root;
	}

	ParseResult World::merge(const World& newWorld)
	{
		return root->merge(newWorld->root);
	}

	ParseResult World::parse(const std::string& str)
	{
		Parser parser;
		SectionResult result = parser.parse(str, root);
		if(result.type!=ParseResult::EOK)
			return 
	}

	ParseResult World::verify() const
	{
		return ParseResult();
	}
}