#include "lexer.h"
extern "C"
{
	extern int   yylex();
	extern char* yytext;
	extern int   yyleng;
	extern void* lexSetUpBuffer(char const* text);
	extern void  lexTearDownBuffer(void* buffer);
}

namespace fabula
{
	Lexer::Lexer() : mLexBuffer(NULL), hasPeeked(false), lastToken(TIGNORE)
	{

	}

	Lexer::~Lexer()
	{
		clear();
	}

	void Lexer::lex(const std::string& str)
	{
		clear();
		mLexBuffer = lexSetUpBuffer(str.c_str());
		if (mLexBuffer == 0)
			throw FabulaException("Could not set up FLEX buffer.");
	}

	Token Lexer::next()
	{
		//If we have peeked, we are actually already at the next token.
		if (hasPeeked)
			hasPeeked = false;
		else
			do
			{
				lastToken = (Token)yylex();
			} while (lastToken == TIGNORE && lastToken != TEOF);

		if (lastToken == TERROR)
			throw ParseException("Unable to parse token.", line(), ParseException::ELEXING_ERROR);
		return lastToken;
	}

	Token Lexer::peek()
	{
		if (!hasPeeked)
		{
			hasPeeked = true;
			do
			{
				lastToken = (Token)yylex();
				if (lastToken == TERROR)
					throw ParseException("Unable to parse token.", line(), ParseException::ELEXING_ERROR);
			} while (lastToken == TIGNORE && lastToken != TEOF);
		}
		return lastToken;
	}

	int Lexer::line() const
	{
		return yyleng;
	}

	const char* Lexer::string() const
	{
		return yytext;
	}

	void Lexer::clear()
	{
		hasPeeked = false;
		if (mLexBuffer != NULL)
			lexTearDownBuffer(mLexBuffer);
		mLexBuffer = NULL;
	}
}