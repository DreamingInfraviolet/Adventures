#include <cassert>
#include "parser.h"
#include "section.h"
#include "content.h"
#include "choice.h"
#include "world.h"
#include "scene.h"

namespace fabula
{
	Section* Parser::enterSection(String name, bool start = false)
	{
		Section* section = new Section(lexer.line());
		if (start)
			section->name = name;

		while (true)
		{
			Token t = lexer.next();
			switch (t)
			{
			//We have parsed the scene keyword, so switch to scene parsing mode.
			case TSCENE:
			{
				Scene scene = enterScene(section);
				unsigned sceneId = (world->addScene(scene));
				section->addScene(scene.name(), sceneId);
			}
			break;
			//An identifier denotes the name of a new section.
			case TIDENTIFIER:
			{
				String innerName = String(lexer.string());

				//The next token must be '[' denoting the section beginning..
				if (lexer.next() != TBRACKET_SQUARE_OPEN)
					throw ParseException("Expected '[' after section name.", lexer.line(), ParseException::E_PARSING_ERROR);
				else
					section->addChild(enterSection(innerName));
			}
			break;
			//If we are inside a section, we need a way to know when to stop trying to parse its contents and leave.
			//As the starting section does not have [ or ] symbols, two cases must be considered.
			case TBRACKET_SQUARE_CLOSE:
				if (start)
					throw ParseException("Unexpected ']' in the default section.", lexer.line(), ParseException::E_PARSING_ERROR);
			case TEOF:
				if (!start)
					throw ParseException("Expected ']' at the end of input.", lexer.line(), ParseException::E_PARSING_ERROR);

				//If all is valid, return the scene we have constructed.
				return section;
			default:
				throw ParseException("Unexpected token.", lexer.line(), ParseException::E_PARSING_ERROR);
			}
		}
	}

	//Starts just after the scene keyword.
	Scene Parser::enterScene(Section* parent)
	{
		Scene scene(lexer.line(), parent);
		//The next token must be the name of the scene.
		if (lexer.next() != TIDENTIFIER)
			throw ParseException("Expected scene name after 'scene' keyword.", lexer.line(), ParseException::E_PARSING_ERROR);
		scene.setName(lexer.string());
		if (lexer.next() != TBRACKET_CURLY_OPEN)
			throw ParseException("Expected '{' after scene name.", lexer.line(), ParseException::E_PARSING_ERROR);

		//Get the strings. If only one, there's no header.
		if (lexer.next() != TSTRING)
			throw ParseException("Expected string after '{'.", lexer.line(), ParseException::E_PARSING_ERROR);

		Content content = enterContentStrings();
		scene.setContent(content);

		//Now we are pointing to the last string.
		//We need to parse all choices/goto statements.
		Token t;
		bool defaultDestinationSet = false;
		while ((t = lexer.next()) != TBRACKET_CURLY_CLOSE)
		{
			if (t == TCHOICE)
				scene.addChoice(enterChoice());
			else if (t == TGOTO)
			{
				if (defaultDestinationSet)
					throw ParseException("Encountered multiple default goto statements.", lexer.line(), ParseException::E_PARSING_ERROR);
				scene.setDefaultDestination(enterGoto());
				defaultDestinationSet = true;
			}
			else
				throw ParseException("Expected 'choice' or 'goto' after scene description.", lexer.line(), ParseException::E_PARSING_ERROR);
		}
		return scene;
	}

	//Parses header/description strings or only the descriptin based on what exists.
	//Starts at string
	//and ends at the second string.
	Content Parser::enterContentStrings()
	{
		String str1(lexer.string());
		//If no second string
		if (lexer.peek() != TSTRING)
			return Content(String(""), str1);
		else
			return Content(str1, String(lexer.string()));
	}

	//Starts at the choice keyword
	//Ends after
	Choice Parser::enterChoice()
	{
		Choice choice;
		if (lexer.next() != TSTRING)
			throw ParseError("Expected a string after 'choice'.", lexer.line(), ParseException::E_PARSING_ERROR);
		Content content = enterContentStrings();
		choice.setContent(content);
		if (lexer.next() != TGOTO)
			throw ParseError("Expected GOTO after choice description.", lexer.line(), ParseException::E_PARSING_ERROR);
		choice.setDestination(enterGoto());
		return choice;
	}

	//Starts at the goto statement
	//Ends after
	Destination Parser::enterGoto()
	{
		Destination dest;
		bool somethingAdded = false;
		while (true)
		{
			Token t;
			switch (t = lexer.next())
			{
			case TARROW_LEFT:
			{
				dest.addLeftArrow();
				somethingAdded = true;
			}
			break;
			case TARROW_RIGHT:
			{
				dest.addRightArrow();
				somethingAdded = true;
			}
			break;
			case TFULLSTOP:
			{
				dest.addIdentifier();
				somethingAdded = true;
			}
			break;
			default: //If it's none of those, we are finished.
					 //If there is nothing after the goto statement that matches, it's guaranteed to be invalid.
				if (!somethingAdded)
					throw ParseException("Empty goto statement.", lexer.line(), ParseException::E_PARSING_ERROR);
				return dest;
			}
		}
		assert(false);
	}

	World* world;

	World Parser::parse(const std::string& str)
	{
		lexer.lex(str);
		world = new World();
		world->root = enterSection("default", true);
		lexer.clear();
		return world;
	}
}