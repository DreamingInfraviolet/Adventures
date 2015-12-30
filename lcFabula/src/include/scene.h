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
        Header mContent;
		std::vector<Choice> mChoices;
		Destination mDestination;
        bool mFinal;
		
	public:

		Scene() :  mFinal(true) {}

		Scene(const std::vector<Choice>&& choices)
			: mChoices(choices) {}

		Scene(const Destination& destination)
			: mDestination(destination) {}


		void header(const Header& content) { mContent = content; }

		void name(const std::string& str) { mName = str; }

		bool final() const { return mFinal; }

		std::string name() const { return mName; }
    };
}