#pragma once

/**
  * @author Anima Seteine
  * @purpose Holds basic information about a destination.
  *          This information is relative to the parse tree, and may be invalid during parsing.
  */

#include <vector>
#include <string>

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
			class Destination
			{
				std::vector<std::string> mLocationChain;
				int                 mBacksteps      = 0;
				bool                mRelative       = true;

			public:
				/** Initialises an empty destination . */
				Destination();

				/** Constructs a destination with the given location in the chain. */
				Destination(std::string location);

				/** Constructs a destination with an empty location chain but with the inputted arguments. */
				Destination(int backsteps, bool relative);

				/** Appends the inputted location onto the location chain. */
				void appendLocation(const std::string& location);

				/** Sets the number of backsteps (number of times to jump to parent before starting on the chain) */
				void backsteps(int n);

				/** Returns the current number of backsteps. */
				int backsteps();

				/** Sets whether the path should be relative. */
				void relative(bool r);

				/** Returns true if the destination is relative to its parent scene. */
				bool relative();
			};
		}
	}
}