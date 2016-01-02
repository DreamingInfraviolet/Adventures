#include <iostream>
#include "fparser.h"
#include "html_writer.h"
#include <fstream>
#include <sstream>
#include "section.h"
#include "scene.h"
#include "header.h"
#include "choice.h"
#include "destination.h"

/* IDEA. Use a different technique for traversing the parse tree. Instead
of having each tree know what it does, have a separate class that has
an accept method that accepts each node. Pass this to the root node, and
have it call accept() on itself before recursively passing it on. */

using namespace std;
using namespace fabula;
using namespace fabula::parsing;
using namespace fabula::parsing::node;

std::string getPrefix(Section* section)
{
	Section* next = section;
	std::string prefix = section->name();

	while ((next=dynamic_cast<Section*>(next->parent())) != nullptr)
		prefix = next->name() + "." + prefix;

	prefix = std::string("fabula") + prefix;
	return prefix;
}

void handleScene(Scene* scene, Section* parent)
{
	std::ofstream file(getPrefix(parent) + "." + scene->name() + ".html");
	fabula::HtmlWriter writer(file);
	writer.doctype();
	writer.header(std::string("Fabula - ") + scene->name(), { "main.css" });
	writer.push("body");

	//Header
	writer.push("h1");
	writer.writeBytes(scene->mHeader->mTitle._str);
	writer.pop();
	writer.br();
	writer.push("h2");
	writer.writeBytes(scene->mHeader->mDescription._str);
	writer.pop();
	writer.br();
	writer.br();

	//Write choices
	writer.push("ul");
	if(scene->mChoices)
		for (Choice* c : *scene->mChoices)
		{
			Scene* dest = c->mDestination->getScene();
			Section* destS = dynamic_cast<Section*>(dest->parent());

			writer.push("li");
			writer.push("a", { {"href", getPrefix(destS) + "." + dest->name() + ".html"} });
			writer.push("h3");
			writer.writeBytes(c->mHeader->mTitle._str);
			writer.pop();//h3
			writer.push("h2");
			writer.writeBytes(c->mHeader->mDescription._str);
			writer.pop();//h2
			writer.pop();//a
			writer.pop();//li
		}
	writer.pop();//ul


	writer.pop(); //body
}

void handleSection(Section* section)
{
	//Write each scene
	for (auto scene = section->mScenes.begin(); scene != section->mScenes.end(); ++scene)
		handleScene(scene->second, section);

	//Handle each subsections
	for (auto s = section->mSubsections.begin(); s != section->mSubsections.end(); ++s)
		handleSection(s->second);

}
extern int fyydebug;
int main(int argc, char** argv)
{
	fyydebug = 0;
	std::fstream file("input.fab");
	if (file.fail())
	{
		std::cout << "Unable to open file\n";
		return 1;
	}

 	fabula::parsing::Parser* parser = fabula::parsing::Parser::create(file, "");
	parser->parse();
	//////////////////////////////////////////////////////////////////////////////////////
	handleSection(parser->getParseResult());
	//////////////////////////////////////////////////////////////////////////////////////
	fabula::parsing::Parser::destroy(parser);
}