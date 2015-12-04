#pragma once
#include<sstream>
#include<string>
#include <vector>
class XmlHelper
{
	std::ostringstream stream;
	std::vector<std::string> stack;
	int indentationLevel = 0;

	void indent(int level);
public:

	void start(const std::string & name,
		const std::initializer_list<const std::pair<const std::string, const std::string>>& attributes = {});
	void end();
	void line(const std::string& l);
	std::string str() const;
};

