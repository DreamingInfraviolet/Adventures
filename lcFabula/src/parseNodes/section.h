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
				std::string                     mName;
				std::map<std::string, Scene*>   mScenes;
				std::map<std::string, Section*> mSubsections;
			public:


				/** Initialises an empty section with no children. */
				Section();

				/** Destroys all child elements. */
				~Section();

				/** Sets the name of the section. */
				void name(const std::string& name);

				/** Returns the name of the section. */
				std::string name() const;

				/** Returns start scenes iterator. */
				std::map<std::string, Scene*>::iterator scenesBegin();

				/** Returns end scenes iterator. */
				std::map<std::string, Scene*>::iterator scenesEnd();

				/** Returns the start subsections iterator. */
				std::map<std::string, Section*>::iterator sectionsBegin();

				/** Returns the end subsections iterator. */
				std::map<std::string, Section*>::iterator sectionsEnd();

				/** Adds a child section, taking ownership of the argument. */
				void add(Section* s);

				/** Adds a child scene, taking ownership of the argument. */
				void add(Scene* s);

				/** Returns the corresponding node type of the class. */
				virtual NodeType nodeType();

				/** returns whether the section has a subsection with a given name. */
				bool hasSubsection (const std::string& name) const;

				/** returns whether the scene has a subsection with a given name. */
				bool hasScene (const std::string& name) const;

				/** Returns a subsection given a name, returning null if none exists. */
				Section* getSubsection(const std::string& name);

				/** Returns a scene given a name, returning null if none exists. */
				Scene* getScene(const std::string& name);
		    };
		}
	}
}