#pragma once
#include <string>
namespace fabula
{
	struct FabulaException : public std::exception
	{
		enum Type { EUNKNOWN, EALLOCATION_ERROR, ELEXING_ERROR, E_PARSING_ERROR };

		//The error message upon failure.
		std::string message;

		Type type;

		FabulaException() : type(EUNKNOWN) {}
		FabulaException(const std::string& message_, Type type_ = EUNKNOWN)
			: message(message_), type(type_) {}
	};

	struct ParseException : public FabulaException
	{
	public:
		int line;

		ParseException() : FabulaException(), line(0) {}
		ParseException(const std::string& message_, int line_, Type type_)
			: FabulaException(message_, type_), line(line_) {}
	};
}