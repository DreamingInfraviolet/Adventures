#pragma once
#include "fstring.h"
#include <map>

namespace fabula
{
	class Scene;
	class World;

    class Section
    {
		std::string mName;
		std::vector<Scene> mScenes;
		std::vector<Section> mSubsections;

	public:

		Section() {}

		void name(const std::string& name)
		{
			mName = name;
		}

		std::string name() const { return mName; }

		void add(const Section& s)
		{
			mSubsections.push_back(s);
		}

		void add(const Scene& s)
		{
			mScenes.push_back(s);
		}
    };
}