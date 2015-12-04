#pragma once
#include "fstring.h"
#include <map>

namespace fabula
{
	class Scene;
	class World;

    class Section
    {
        String mName;
        std::map<String, Section> mSubsections;
        std::map<String, unsigned> mScenes;
        Section* mParent;
		int mLine;

	public:

		Section(int line) : mLine(line) {}

		void setName(const String& name)
		{
			mName = name;
		}

		String name() const { return mName; }

		int line() const { return mLine; }

		void merge(const Section& sec, World* world);

		void addScene(const String& name, unsigned id)
		{
			if (mScenes.find(name) != mScenes.end())
				throw ParseException("A scene with such a name already exists in the section.", line(), ParseException::E_PARSING_ERROR);
			else
				mScenes[name] = id;
		}

		void addChild(const Section& section)
		{
			if (mSubsections.find(section.name()) != mSubsections.end())
				throw ParseException("A section with such a name already exists in the given context.", section.line(), ParseException::E_PARSING_ERROR);
			else
				mSubsections[section.name()] = section;
		}
    };
}