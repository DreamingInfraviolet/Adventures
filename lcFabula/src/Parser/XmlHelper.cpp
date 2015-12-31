#include "XmlHelper.h"



void XmlHelper::indent(int level)
{
	for (int i = 0; i < level; ++i)
		stream << "    ";
}

void XmlHelper::start(const std::string & name, 
	const std::initializer_list<const std::pair<const std::string, const std::string>>& attributes)
{
	indent(indentationLevel++);
	stack.push_back(name);

	stream << "<" << name;
	for(auto& attr : attributes)
		stream << " " << attr.first << "=\"" << attr.second << "\"";
	stream << ">\n";
}

void XmlHelper::end()
{
	std::string name = stack.back();
	stack.pop_back();
	indent(--indentationLevel);
	stream << "</" << name << ">\n";
}

void XmlHelper::line(const std::string& l)
{
	indent(indentationLevel);
	stream << l << "\n";

}

std::string XmlHelper::str() const
{
	return stream.str();
}
