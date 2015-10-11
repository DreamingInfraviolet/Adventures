#include <stdio.h>
#include "tokens.h"
#include "fabula.h"

int main(int argc, char** argv)
{
    printf("Running Fabula\n");

	fabula::World world;
	fabula::ParseResult::Type result1 = world.parse
		(
			"scene Start "
			"{"
			"\"Header\" \"Body\" "
			"choice \"Jump\" \"Description!\\\"\" goto <-->End "
			"}\n"
			"scene End { \"Yo\" \"Yooo\" goto Start2 }"
			).type;

	if (result1 != fabula::ParseResult::Type::EOK)
		return 1;

	fabula::ParseResult::Type result2 = world.parse
		(
			"scene Start2 "
			"{"
			"\"Header\" \"Body\" "
			"choice \"Jump\" \"Description!\\\"\" goto <-->End2 "
			"}\n"
			"scene End2 { \"Yo\" \"Yooo\" }"
			).type;

	if (result2 != fabula::ParseResult::Type::EOK)
		return 2;

	fabula::ParseResult::Type result3 = world.verify().type;
	if (result3 != fabula::ParseResult::Type::EOK)
		return 3;
 
	printf("Fabula done\n");
}