#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "parser.h"
#include "xml_writer.h"

using namespace std;


std::istringstream inputStream(
	"scene Start \n"
	"{\n"
	"\"Header\" \"Body\"\n"
	"choice { \"Jump\" \"Description!\\\"\" goto /End\n }"
	"}\n"
	"scene End { \"Yo\" \"Yooo\" goto Start2 } \n"
	" scene Start2 {\"XD\" }");	



int main(int argc, char** argv)
{
    cout<<"Running Fabula\n";

	std::cout<<"---------------------------\ninput\n---------------------------\n";
	std::cout << inputStream.str();
	std::cout << "\n---------------------------\nparsing\n---------------------------\n";

	fabula::parsing::Parser* parser = fabula::parsing::Parser::create(inputStream, "");

	parser->parse();

	std::ostringstream str;
	fabula::parsing::XmlWriter writer(str);
	parser->write(writer, str);
	std::cout << "\n---------------------------\nxml\n---------------------------\n";
	std::cout << str.str();

	fabula::parsing::Parser::destroy(parser);

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