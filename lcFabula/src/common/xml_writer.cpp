#include "xml_writer.h"

namespace fabula
{
	namespace parsing
	{
		XmlWriter::XmlWriter(std::ostream& stream)
			: Writer(stream) {}

		void XmlWriter::indent(int level)
		{
			for (int i = 0; i < level; ++i)
				stream << "    ";
		}

		void XmlWriter::push(const std::string& name,
			const std::initializer_list<const std::pair<const std::string, const std::string>>& attributes)
		{
			indent(indentationLevel++);
			stack.push_back(name);

			stream << "<" << name;
			for (auto& attr : attributes)
				stream << " " << attr.first << "=\"" << attr.second << "\"";
			stream << ">\n";
		}

		void XmlWriter::pop()
		{
			std::string name = stack.back();
			stack.pop_back();
			indent(--indentationLevel);
			stream << "</" << name << ">\n";
		}

		void XmlWriter::writeBytes(const std::string& bytes)
		{
			indent(indentationLevel);
			stream << "\"" << bytes << "\"" << "\n";
		}
	}
}