#pragma once
#include "result.h"
#include "tokens.h"
namespace fabula
{
	class Lexer
	{
		void* mLexBuffer;

		//As flex does not seem to have a peek() function, I have to simulate it here.
		bool hasPeeked;
		Token lastToken;
	public:
		Lexer();
		~Lexer();
		void lex(const std::string& str);
		
		//Returns the next token, skipping TIGNORE tokens.
		Token next();
		Token peek();
		int line() const;
		const char* string() const;

		//This clears the global token buffer.
		void clear();
	};
}