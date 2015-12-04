#pragma once
#include "result.h"
#include <vector>

namespace fabula
{
    class World
    {
        class Section;
		class Destination;
		class Scene;

        unsigned int id;
        Section* root;

		void operator=(const World& w) = delete;

		friend class Parser;

		std::vector<Scene> mScenes;

	public:
		World();

		World(Section* root);

		/** Parses a string. */
		void parse(const std::string& str);

		/** Verifies that all the scripts parsed so far have made sense. */
		bool verify() const;

		unsigned addScene(const Scene& scene)
		{
			mScenes.push_back(scene);
			return mScenes.size()-1;
		}

		/** Merges the inputted world into this. */
		void merge(const World& newWorld);

		Scene& getScene(unsigned id)
		{
			return mScenes[id];
		}

		Scene& getScene(const Destination& d);
    };
}