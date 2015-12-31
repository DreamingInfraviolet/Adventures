#include "section.h"
#include "scene.h"

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            Section::Section() {}

            Section::~Section()
            {
                for (Scene* s : mScenes)
                    delete s;
                for (Section* s : mSubsections)
                    delete s;
            }

            void Section::name(const std::string& name)
            {
                mName = name;
            }

            std::string Section::name() const
            {
                return mName;
            }

            void Section::add(Section* s)
            {
                mSubsections.push_back(s);
            }

            void Section::add(Scene* s)
            {
                mScenes.push_back(s);
            }
        }
    }
}