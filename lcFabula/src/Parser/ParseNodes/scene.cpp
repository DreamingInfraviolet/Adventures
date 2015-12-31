#include "scene.h"
#include "header.h"
#include "choice.h"
#include "destination.h"
#include <cassert>

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            Scene::Scene() {}

            Scene::Scene(std::vector<Choice*>* choices)
                : mChoices(choices) {}

            Scene::Scene(Destination* destination)
                : mDestination(destination) {}

            Scene::~Scene()
            {
                if (mChoices)
                    for (Choice* c : *mChoices)
                        delete c;
                delete mChoices;
                delete mHeader;
                delete mDestination;
            }

            void Scene::header(Header* content)
            {
                delete mHeader;
                mHeader = content;
            }

            void Scene::name(const std::string& str)
            {
                mName = str;
            }

            bool Scene::final() const
            {
                return mChoices == nullptr && mDestination == nullptr;
            }

            std::string Scene::name() const
            {
                return mName;
            }

			ParseNode::NodeType Scene::nodeType()
			{
				return NodeType::Scene;
			}

			void Scene::bindChildren()
			{
				if (mHeader)
					mHeader->bindParent(this);

				if (mChoices)
					for (Choice* choice : *mChoices)
					{
						assert(choice);
						choice->bindParent(this);
					}

				if (mDestination)
					mDestination->bindParent(this);
			}

			void Scene::checkSemantics()
			{
			}
        }
    }
}