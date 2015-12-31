#include "scene.h"

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
                delete mContent;
                delete mDestination;
            }

            void Scene::header(Header* content)
            {
                delete mContent;
                mContent = content;
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
        }
    }
}