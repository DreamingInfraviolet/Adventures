#pragma once
#include <vector>
#include "fstring.h"
#include "content.h"
#include "choice.h"
#include "destination.h"

namespace fabula
{
    class Section;

    class Scene
    {
        String mName;
        Content mContent;
		std::vector<Choice> mChoices;
        Section* mParent;
		int mLine;
        bool mFinal;
		

	public:

		Scene(int line, Section* parent) : mLine(line), mParent(parent), mFinal(true) {}

		void setContent(const Content& content) { mContent = content; }

		void setName(const String& str) { mName = str; }

		int line() const { return mLine; }

		bool final() const { return mFinal; }

		Section* parent() const { return mParent; }

		String name() const { return mName; }

		void addChoice(const Choice& choice) { mChoices.push_back(choice); }

    };
}