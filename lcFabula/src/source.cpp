#include <stdio.h>
#include <iostream>
#include <string>
#include "XmlHelper.h"
using namespace std;

int main(int argc, char** argv)
{
    cout<<("Running Fabula\n");

	XmlHelper xml;

	xml.start("html");
	xml.start("head");
	xml.start("title");
	xml.line("Testing");
	xml.end();
	xml.end();
	xml.start("body");
	xml.start("p");
	xml.start("a", { {"src", "help.html"}, {"alt","What?"} });
	xml.end();
	xml.start("a", { {"src","halp.html"} });
	xml.end();
	xml.end();
	xml.end();
	xml.end();

	cout << xml.str();

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
 
	printf("Fabula done\n");
}