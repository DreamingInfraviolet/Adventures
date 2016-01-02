#pragma once

/**
  * @author Anima Seteine
  * @purpose This class holds the information about a section object. A section can contain scenes, or subsections.
  */

#include <string>
#include <map>
#include "parse_node.h"

namespace fabula
{
	namespace parsing
    {
		class Writer;

		namespace node
        {
			class Scene;

		    class Section : public ParseNode
		    {
			public:
				std::string                     mName;
				std::map<std::string, Scene*>   mScenes;
				std::map<std::string, Section*> mSubsections;


				/** Initialises an empty section with no children. */
				Section();

				/** Destroys all child elements. */
				~Section();

				/** Sets the name of the section. */
				void name(const std::string& name);

				/** Returns the name of the section. */
				std::string name() const;

				/** Adds a child section, taking ownership of the argument. */
				void add(Section* s);

				/** Adds a child scene, taking ownership of the argument. */
				void add(Scene* s);

				/** Returns the corresponding node type of the class. */
				virtual NodeType nodeType();

				/** Notifies all children that this is the parent, and calls bindChildren on them. */
				virtual void bindChildren();

				/** Performs semantic error detection, throwing an exception if failed. */
				virtual void checkSemantics();

				/** returns whether the section has a subsection with a given name. */
				bool hasSubsection (const std::string& name) const;

				/** returns whether the scene has a subsection with a given name. */
				bool hasScene (const std::string& name) const;

				/** Returns a subsection given a name, returning null if none exists. */
				Section* getSubsection(const std::string& name);

				/** Returns a scene given a name, returning null if none exists. */
				Scene* getScene(const std::string& name);

				/** Writes the node to a writer class. */
				virtual void write(fabula::parsing::Writer& writer);
		    };
		}
	}
}