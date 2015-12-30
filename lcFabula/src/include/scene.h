#pragma once
#include <vector>
#include "fstring.h"
#include "header.h"
#include "choice.h"
#include "destination.h"

namespace fabula
{
    class Section;

    class Scene
    {
		std::string mName;
        Header* mContent = nullptr;
		std::vector<Choice*>* mChoices = nullptr;
		Destination* mDestination = nullptr;
        bool mFinal;
		
	public:

		Scene() :  mFinal(true) {}

		//Takes ownership
		Scene(std::vector<Choice*>* choices)
			: mChoices(choices) {}

		//Takes ownership
		Scene(Destination* destination)
			: mDestination(destination) {}

		~Scene()
		{
			if (mChoices)
				for (Choice* c : *mChoices)
					delete c;
			delete mChoices;
			delete mContent;
			delete mDestination;
		}

		//Takes ownership
		void header(Header* content)
		{
			delete mContent;
			mContent = content;
		}

		void name(const std::string& str) { mName = str; }

		bool final() const { return mFinal; }

		std::string name() const { return mName; }
    };
}