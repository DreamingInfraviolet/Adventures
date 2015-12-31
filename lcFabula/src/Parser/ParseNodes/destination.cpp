#include "destination.h"
#include <cassert>

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

			ParseNode::NodeType Destination::nodeType()
			{
				return NodeType::Destination;
			}

			void Destination::bindChildren()
			{
			}

			void Destination::checkSemantics()
			{
			}

			void Destination::relative(bool r)
			{
				mRelative = r;
			}
		}
	}
}