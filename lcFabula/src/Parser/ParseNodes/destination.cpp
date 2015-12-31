#include "destination.h"

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
			Destination::Destination() {}

			Destination::Destination(std::string location)
				: mLocationChain(1, location) {}

			Destination::Destination(int backsteps, bool relative)
			{
				mBacksteps = backsteps;
				mRelative = relative;
			}

			void Destination::appendLocation(const std::string& location)
			{
				mLocationChain.push_back(location);
			}

			void Destination::backsteps(int n)
			{
				mBacksteps = n;
			}

			int Destination::backsteps()
			{
				return mBacksteps;
			}

			bool Destination::relative()
			{
				return mRelative;
			}

			void Destination::relative(bool r)
			{
				mRelative = r;
			}
		}
	}
}