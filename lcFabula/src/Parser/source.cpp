#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <FlexLexer.h>
#include <ParseNodes/section.h>
#include "xml_writer.h"

using namespace std;
extern int yyparse();

fabula::parsing::node::Section *parseResult;

std::istringstream inputStream(
	"scene Start \n"
	"{\n"
	"\"Header\" \"Body\"\n"
	"choice { \"Jump\" \"Description!\\\"\" goto /End\n }"
	"}\n"
	"scene End { \"Yo\" \"Yooo\" goto Start2 } \n"
	" scene Start2 {\"XD\" }");	
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

	std::cout<<"---------------------------\ninput\n---------------------------\n";
	std::cout << inputStream.str();
	std::cout << "\n---------------------------\nparsing\n---------------------------\n";

	yyparse();

	parseResult->initiateParentBinding(nullptr);
	parseResult->checkSemantics();

	std::ostringstream str;
	fabula::parsing::XmlWriter writer(str);
	parseResult->write(&writer);
	std::cout << "\n---------------------------\nxml\n---------------------------\n";
	std::cout << str.str();

	/*
	fabula::World world;
	world.parse
		(
			"scene Start \n"
			"{\n"
			"\"Header\" \"Body\"\n"
			"choice \"Jump\" \"Description!\\\"\" goto .End\n"	
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