#pragma once

/**
  * @author Anima Seteine
  * @purpose This class holds the information about a section object.
  */

#include <vector>
#include <string>

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
			class Scene;

		    class Section
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
		    };
		}
	}
}