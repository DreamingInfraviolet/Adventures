#pragma once

/**
  * @author Anima Seteine
  * @purpose This class holds the information about a section object. A section can contain scenes, or subsections.
  */

#include <vector>
#include <string>
#include "parse_node.h"

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
			class Scene;

		    class Section : public ParseNode
		    {
				std::string           mName;
				std::vector<Scene*>   mScenes;
				std::vector<Section*> mSubsections;

			public:

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
		    };
		}
	}
}