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
#include <regex>
#include "header.h"
#include "choice.h"

#include "util.h"
#include "destination.h"


using namespace std;
using namespace fabula;
using namespace fabula::parsing;
using namespace fabula::parsing::node;


namespace fabula
{
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

		NameManager(bool scrambleNames = true)
			: mScrambleNames(scrambleNames) { }

		void generateNames(Section* root)
		{
			_generateNames(root);
			if (mScrambleNames)
				scrambleNames();

			Scene* start = root->findStartScene();
			assert(start);

			nameMapping[start] = "main";
		}

		std::string getName(Scene* scene)
		{
			return nameMapping[scene] + ".html";
		}

	};

	class HtmlInterface
	{
		NameManager nameManager;
		std::string templateStr;

		std::regex nameRegex;
		std::regex headRegex;
		std::regex descRegex;
		std::regex choicesRegex;

		void handleScene(Scene* scene, Section* parent)
		{
			assert(scene);
			assert(parent);

			std::ofstream file(nameManager.getName(scene));

			std::string str(templateStr);

			std::ostringstream choicesStr;
			HtmlWriter writer(choicesStr);

			//Write choices
			writer.push("ul");
			if (scene->choices())
				for (Choice* c : *scene->choices())
				{
					Scene* dest = c->destination().getScene();
					Section* destS = dynamic_cast<Section*>(dest->parent());

					writer.push("li");
					writer.push("a", { { "href", nameManager.getName(dest) } });
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

			str = std::regex_replace(
				std::regex_replace(
					std::regex_replace(
						std::regex_replace(
							str, choicesRegex, choicesStr.str()),
						descRegex, scene->header().description().string()),
					headRegex, scene->header().title().string()),
				nameRegex, scene->name());

			file << str;
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

	public:

		HtmlInterface()
			: nameRegex("\\[\\$\\s*scene_name\\s*\\$\\]"),
			  headRegex("\\[\\$\\s*head\\s*\\$\\]"),
			  descRegex("\\[\\$\\s*desc\\s*\\$\\]"),
			  choicesRegex("\\[\\$\\s*choices\\s*\\$\\]") { }

		void process(Section* root)
		{
			nameManager.generateNames(root);
			handleSection(root);
		}

		void setTemplateString(const std::string& str)
		{
			templateStr = str;
		}
	};
}



extern int fyydebug;
int main(int argc, char** argv)
{
	fyydebug = 0;
	std::fstream file("input.fab");
	if (file.fail())
	{
		std::cout << "Unable to open input fabula file\n";
		return 1;
	}
	
	std::fstream templateFile("template.html");
	if (templateFile.fail())
	{
		std::cout << "Unable to open template file\n";
		return 2;
	}

	std::string templateStr = std::string(std::istreambuf_iterator<char>(templateFile), std::istreambuf_iterator<char>());

 	fabula::parsing::Parser* parser = fabula::parsing::Parser::create(file, "");
	parser->parse();
	//////////////////////////////////////////////////////////////////////////////////////
	HtmlInterface interface;
	interface.setTemplateString(templateStr);
	interface.process(parser->getParseResult());
	//////////////////////////////////////////////////////////////////////////////////////
	fabula::parsing::Parser::destroy(parser);
}