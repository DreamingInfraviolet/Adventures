#pragma once
#include <vector>
#include "fstring.h"

namespace fabula
{
	class Destination
	{

		std::vector<String> mLocationChain;
		int mBacksteps = 0;
		bool mRelative = true;

	public:
		Destination() {}

		//Constructs a destination based on a single location.
		Destination(std::string location)
			: mLocationChain(1, location) {}

		//Constructs a new destination based on the base location with app appended. */
		Destination(const Destination& base, const String& app)
		{
			mLocationChain = base.mLocationChain;
			mLocationChain.push_back(app);
		}

		Destination(int backsteps, bool relative)
		{
			mBacksteps = backsteps;
			mRelative = relative;
		}

		void backsteps(int n)
		{
			mBacksteps = n;
		}

		int backsteps()
		{
			return mBacksteps;
		}

		bool relative()
		{
			return mRelative;
		}
	};
}