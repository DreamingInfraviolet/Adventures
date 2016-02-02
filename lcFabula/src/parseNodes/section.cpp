#include "section.h"
#include "scene.h"
#include <cassert>
#include "parse_exception.h"
#include <set>
#include "parse_tree_visitor.h"

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            Section::Section() {}

            Section::~Section()
            {
				for (auto it = mScenes.begin(); it != mScenes.end(); ++it)
                    delete it->second;
				for (auto it = mSubsections.begin(); it != mSubsections.end(); ++it)
					delete it->second;
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
				assert(s);
				if (hasScene(s->name()))
					throw SemanticException("A scene with such a name already exists!");
				if (hasSubsection(s->name()))
					throw SemanticException("A subsection with such a name already exists!");
	            mSubsections[s->name()] = s;
            }

            void Section::add(Scene* s)
            {
				assert(s);
				if (hasScene(s->name()))
					throw SemanticException("A scene with such a name already exists!");
				if (hasSubsection(s->name()))
					throw SemanticException("A subsection with such a name already exists!");
				mScenes[s->name()] = s;
            }

			ParseNode::NodeType Section::nodeType()
			{
				return NodeType::Section;
			}

			std::map<std::string, Scene*>::iterator Section::scenesBegin()
			{
				return mScenes.begin();
			}

			std::map<std::string, Scene*>::iterator Section::scenesEnd()
			{
				return mScenes.end();
			}

			std::map<std::string, Section*>::iterator Section::sectionsBegin()
			{
				return mSubsections.begin();
			}

			std::map<std::string, Section*>::iterator Section::sectionsEnd()
			{
				return mSubsections.end();
			}

			bool Section::hasSubsection (const std::string& name) const
			{
				return (bool)mSubsections.count(name);
			}

			bool Section::hasScene (const std::string& name) const
			{
				return (bool)mScenes.count(name);
			}

			Section * Section::getSubsection(const std::string& name)
			{
				auto it = mSubsections.find(name);
				if (it == mSubsections.end())
					return nullptr;
				else
					return it->second;
			}

			Scene * Section::getScene(const std::string& name)
			{
				auto it = mScenes.find(name);
				if (it == mScenes.end())
					return nullptr;
				else
					return it->second;
			}

			Scene* Section::findStartScene()
			{
				if (hasScene("main"))
					return getScene("main");
				else for (auto s = sectionsBegin(); s != sectionsEnd(); ++s)
				{
					assert(s->second);
					Scene* sc = s->second->findStartScene();
					if (sc)
						return sc;
				}

				return nullptr;
			}
        }
    }
}