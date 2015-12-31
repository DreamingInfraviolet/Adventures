#pragma once

/**
  * @author Anima Seteine
  * @purpose A node to store information about a scene.
  */


#include <vector>
#include <string>

namespace fabula
{
	namespace parsing
	{
		namespace node
		{
			class Section;
			class Choice;
			class Header;
			class Destination;

			class Scene
			{
			    std::string           mName;
			    Header*               mContent     = nullptr;
			    std::vector<Choice*>* mChoices     = nullptr;
			    Destination*          mDestination = nullptr;

			public:

				/** Initialises a fully empty scene. */
			    Scene();

			    /** Initialises a scene with the given choices, taking ownership of the arguments. */
			    Scene(std::vector<Choice*>* choices);

			    /** Initialises a scene from a destination, taking ownership of the argument. */
			    Scene(Destination* destination);

			    /** Destroys all nested nodes. */
			    ~Scene();

			    /** Sets the header of the scene, taking ownership of the argument. */
			    void header(Header* content);

			    /** Sets the current name of the scene. */
			    void name(const std::string& str);

			    /** Returns true if the scene does not have an outgoing path. */
			    bool final() const;

			    /** Returns the current name of the scene. */
			    std::string name() const;
			};
		}
	}
}