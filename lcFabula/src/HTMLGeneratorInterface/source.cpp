#include <iostream>
#include "fparser.h"
#include "html_writer.h"
#include <fstream>
#include <sstream>
#include <map>
#include <cassert>
#include <algorithm>
#include "section.h"
#include "scene.h"
#include <random>
#include "header.h"
#include "choice.h"
#include "util.h"
#include "destination.h"


using namespace std;
using namespace fabula;
using namespace fabula::parsing;
using namespace fabula::parsing::node;

//One is guaranteed to exist after the semantic checks
Scene* findStartScene(Section* root)
{
	assert(root);

	if (root->hasScene("main"))
		return root->getScene("main");
	else for (auto s = root->sectionsBegin(); s != root->sectionsEnd(); ++s)
	{
		assert(s->second);
		Scene* sc = findStartScene(s->second);
		if (sc)
			return sc;
	}

	return nullptr;
}

class NameManager
{
	bool mScrambleNames;
	std::map<Scene*, std::string> nameMapping;

	void _generateNames(Section* root)
	{
		assert(root);

		//Go through each subsection
		for (auto s = root->sectionsBegin(); s != root->sectionsEnd(); ++s)
		{
			assert(s->second);
			_generateNames(s->second);
		}

		//Register names of each scene
		for (auto s = root->scenesBegin(); s != root->scenesEnd(); ++s)
		{
			assert(s->second);
			addName(root, s->second);
		}

	}

	void scrambleNames()
	{
		//Generate consecutive numbers and shuffle them
		std::vector<int> numbers;
		numbers.resize(nameMapping.size());
		for (size_t i = 0; i < numbers.size(); ++i)
			numbers[i] = i;

		std::random_shuffle(numbers.begin(), numbers.end());

		//Set random numbers as new names
		int i = 0;
		for (auto mapping = nameMapping.begin(); mapping != nameMapping.end(); ++mapping)
			mapping->second = toString(numbers[i++]);

	}

	void addName(Section* section, Scene* scene)
	{
		assert(section);
		assert(scene);

		Section* next = section;
		std::string prefix = section->name();
		std::string postfix = scene->name();

		while ((next = dynamic_cast<Section*>(next->parent())) != nullptr)
			prefix = next->name() + "." + prefix;

		nameMapping[scene] = prefix + postfix;
	}

public:

	NameManager(bool scrambleNames=true)
		: mScrambleNames(scrambleNames) { }

	void generateNames(Section* root)
	{
		_generateNames(root);
		if (mScrambleNames)
			scrambleNames();

		Scene* start = findStartScene(root);
		assert(start);

		nameMapping[start] = "main";
	}

	std::string getName(Scene* scene)
	{
		return nameMapping[scene] + ".html";
	}
	
};

NameManager nameManager;

void handleScene(Scene* scene, Section* parent)
{
	std::ofstream file(nameManager.getName(scene));
	fabula::HtmlWriter writer(file);
	writer.doctype();
	writer.header(std::string("Fabula - ") + scene->name(), { "main.css" });
	writer.push("body");

	//Header
	writer.push("h1");
	writer.writeBytes(scene->header().title().string());
	writer.pop();
	writer.br();
	writer.push("h2");
	writer.writeBytes(scene->header().description().string());
	writer.pop();
	writer.br();
	writer.br();

	//Write choices
	writer.push("ul");
	if(scene->choices())
		for (Choice* c : *scene->choices())
		{
			Scene* dest = c->destination().getScene();
			Section* destS = dynamic_cast<Section*>(dest->parent());

			writer.push("li");
			writer.push("a", { {"href", nameManager.getName(dest)} });
			writer.push("h3");
			writer.writeBytes(c->header().title().string());
			writer.pop();//h3
			writer.push("h2");
			writer.writeBytes(c->header().description().string());
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
	for (auto scene = section->scenesBegin(); scene != section->scenesEnd(); ++scene)
		handleScene(scene->second, section);

	//Handle each subsections
	for (auto s = section->sectionsBegin(); s != section->sectionsEnd(); ++s)
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
	nameManager.generateNames(parser->getParseResult());
	handleSection(parser->getParseResult());
	//////////////////////////////////////////////////////////////////////////////////////
	fabula::parsing::Parser::destroy(parser);
}