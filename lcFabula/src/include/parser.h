#pragma once
#include "content.h"
#include "choice.h"
#include "lexer.h"

namespace fabula
{
	class World;
	class Destination;
	class Section;
	class Scene;

	class Parser
	{
		Lexer lexer;

		//Call after parsing '['
		//Returns the appropriate section object
		Section* enterSection(String name, bool start = false);

		//Starts just after the scene keyword.
		Scene enterScene(Section* parent);

		//Parses header/description strings or only the descriptin based on what exists.
		//Starts at string
		//and ends at the second string.
		Content enterContentStrings();
		//Starts at the choice keyword
		//Ends after
		Choice enterChoice();

		//Starts at the goto statement
		//Ends after
		Destination enterGoto();
	public:

		World* world;

		World parse(const std::string& str);
	};
}