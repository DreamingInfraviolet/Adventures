#include "section.h"
#include "world.h"

namespace fabula
{
	void Section::merge(const Section& sec, World* world)
	{
		//Merge sections recursively
		for (auto it = sec.mSubsections.begin(); it != sec.mSubsections.end(); ++it)
		{
			//If the subsection with such a name already exists, marge the inner subsections
			decltype(mSubsections)::iterator secondIt;
			if ((secondIt = mSubsections.find(it->first)) != mSubsections.end())
				secondIt->second.merge(secondIt->second);
		}

		//Try to merge scenes, avoiding clashes:
		for (auto it = sec.mScenes.begin(); it != sec.mScenes.end(); ++it)
		{
			decltype(mScenes)::iterator it2;
			if ((it2 = mScenes.find(it->first)) != mScenes.end())
				throw ParseException("Unable to merge scripts: A scene with such a name already exists in the current context.", world->getScene(it2->second)->line(), FabulaException::Type::E_PARSING_ERROR);
			else
				addScene(world->getScene(it2->second).name(), it2->second);
		}
	}
}