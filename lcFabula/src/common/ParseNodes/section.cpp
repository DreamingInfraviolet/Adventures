#include "section.h"
#include "scene.h"
#include <cassert>
#include "parse_exception.h"
#include <set>
#include "writer.h"

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

			void Section::bindChildren()
			{
				for (auto it = mScenes.begin(); it != mScenes.end(); ++it)
				{
					assert(it->second);
					it->second->initiateParentBinding(this);
				}
				for (auto it = mSubsections.begin(); it != mSubsections.end(); ++it)
				{
					assert(it->second);
					it->second->initiateParentBinding(this);
				}
			}

			void Section::checkSemantics()
			{
				//In this rather unique scenario, the semantics are guaranteed to be already checked
				//due to how the values are stored in a map for efficiency and were checked beforehand.
				//So just call the method on the children instead ^.^

				for (auto it = mScenes.begin(); it != mScenes.end(); ++it)
				{
					assert(it->second);
					it->second->checkSemantics();
				}
				for (auto it = mSubsections.begin(); it != mSubsections.end(); ++it)
				{
					assert(it->second);
					it->second->checkSemantics();
				}
			}

			bool Section::hasSubsection (const std::string& name) const
			{
				return mSubsections.count(name);
			}

			bool Section::hasScene (const std::string& name) const
			{
				return mScenes.count(name);
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


			void Section::write(fabula::parsing::Writer& writer)
			{
				writer.push("section", { {"name", mName} });

				for (auto it = mScenes.begin(); it != mScenes.end(); ++it)
				{
					assert(it->second);
					it->second->write(writer);
				}
				for (auto it = mSubsections.begin(); it != mSubsections.end(); ++it)
				{
					assert(it->second);
					it->second->write(writer);
				}

				writer.pop();
			}
        }
    }
}