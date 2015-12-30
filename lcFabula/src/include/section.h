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
		std::vector<Scene*> mScenes;
		std::vector<Section*> mSubsections;

	public:

		Section() {}

		~Section()
		{
			for (Scene* s : mScenes)
				delete s;
			for (Section* s : mSubsections)
				delete s;
		}

		void name(const std::string& name)
		{
			mName = name;
		}

		std::string name() const { return mName; }

		void add(Section* s)
		{
			mSubsections.push_back(s);
		}

		void add(Scene* s)
		{
			mScenes.push_back(s);
		}
    };
}