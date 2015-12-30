#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "FlexLexer.h"

using namespace std;
extern int yyparse();

std::istringstream inputStream("hi []");
std::ostringstream outputStream;

yyFlexLexer lexer(&inputStream, &outputStream);


int yylex()
{
	return lexer.yylex();
}

extern int yydebug;

int main(int argc, char** argv)
{
    cout<<"Running Fabula\n";
	yydebug = 0;
	yyparse();


	/*
	fabula::World world;
	world.parse
		(
			"scene Start "
			"{"
			"\"Header\" \"Body\" "
			"choice \"Jump\" \"Description!\\\"\" goto <-->End "
			"}\n"
			"scene End { \"Yo\" \"Yooo\" goto Start2 }"
			);

	world.parse
		(
			"scene Start2 "
			"{"
			"\"Header\" \"Body\" "
			"choice \"Jump\" \"Description!\\\"\" goto <-->End2 "
			"}\n"
			"scene End2 { \"Yo\" \"Yooo\" }"
			);


	if (!world.verify())
		return 1;

	string xml = world.xml();
	*/
 
 	cout << "Fabula done\n";
}