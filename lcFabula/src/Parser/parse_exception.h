#pragma once
#include <string>
namespace fabula
{
	namespace parsing
	{
		class ParseException : public std::exception
		{
		public:
			std::string message;
			int line;
			Type type;

			ParseException() {}
			ParseException(const std::string& message_)
				: message(message_) {}
		};

		class SyntacticException : public ParseException
		{
		public:
			SyntacticException() : ParseException(), line(0) {}
			SyntacticException(const std::string& message_, int line_)
				: ParseException(message_), line(line_) {}
		};

		class SyntacticException : public ParseException
		{
		public:
			SyntacticException() : ParseException(), line(0) {}
			SyntacticException(const std::string& message_, int line_)
				: ParseException(message_), line(line_) {}
		};
	}
}