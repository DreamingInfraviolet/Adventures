#pragma once

/**
  * @author Anima Seteine
  * @purpose This class holds the information about a single choice option.
  */

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            class Header;
            class Destination;

            class Choice
            {
                Header*      mHeader      = nullptr;
                Destination* mDestination = nullptr;

        	public:
        		/** Initialises a choice, taking ownership of the arguments. */
        		Choice(Header* header, Destination* destination);

                /** Destroys the choice, deleting the children. */
        		~Choice();
            };
        }
    }
}