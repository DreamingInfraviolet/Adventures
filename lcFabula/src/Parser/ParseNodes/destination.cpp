#include "destination.h"
#include <cassert>
#include "scene.h"
#include "section.h"
#include "parse_exception.h"
#include "choice.h"
#include "writer.h"
#include "util.h"

extern fabula::parsing::node::Section* parseResult;

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
			Destination::Destination() {}

			Destination::Destination(std::string location)
				: mLocationChain(1, location) {}

			Destination::Destination(int backsteps, bool relative)
			{
				mBacksteps = backsteps;
				mRelative = relative;
			}

			void Destination::appendLocation(const std::string& location)
			{
				mLocationChain.push_back(location);
			}

			void Destination::backsteps(int n)
			{
				mBacksteps = n;
			}

			int Destination::backsteps()
			{
				return mBacksteps;
			}

			bool Destination::relative()
			{
				return mRelative;
			}

			ParseNode::NodeType Destination::nodeType()
			{
				return NodeType::Destination;
			}

			void Destination::bindChildren()
			{
			}

			void Destination::checkSemantics()
			{
				getScene(true);
			}

			Scene * Destination::getScene(bool throwSemanticException)
			{
#define CONDITIONAL_THROW(message) if (throwSemanticException) throw SemanticException(message); else return nullptr

				//Get the start node
				Section* currentNode = nullptr;

				if (mRelative)
				{
					assert(parent());

					//Get parent scene. We may be in choice, or not!
					Scene* parentScene;

					if (parent()->nodeType() == ParseNode::NodeType::Choice)
					{
						Choice* parentChoice = dynamic_cast<Choice*>(parent());
						assert(parentChoice && parentChoice->parent());
						parentScene = dynamic_cast<Scene*>(parentChoice->parent());
					}
					else if (parent()->nodeType() == ParseNode::NodeType::Scene)
						parentScene = dynamic_cast<Scene*>(parent());
					else
						assert(false);
					
					assert(parentScene && parentScene->parent());
					Section* parentSection = dynamic_cast<Section*>(parentScene->parent());
					assert(parentSection);
					currentNode = parentSection;

					for (int i = 0; i < mBacksteps; ++i)
					{
						if (!currentNode->parent())
							CONDITIONAL_THROW("Attempting to index section below root section.");
						else
						{
							currentNode = dynamic_cast<Section*>(currentNode->parent());
							assert(currentNode);
						}
					}
				}
				else
				{
					assert(parseResult);
					assert(mBacksteps == 0);
					currentNode = parseResult;
				}

				//Now that we have the start, we need to traverse the location chain.
				assert(mLocationChain.size());

				for (auto it = mLocationChain.begin(); it != mLocationChain.end() - 1; ++it)
				{
					Section* previous = currentNode;
					currentNode = currentNode->getSubsection(*it);
					if (!currentNode)
						CONDITIONAL_THROW("Invalid location: Subsection " + *it +
							" does not exist in " + previous->name());
				}

				//Get and check the final thing on the chain, which is supposed to be a scene.
				std::string sceneName = mLocationChain.back();
				Scene* scene = currentNode->getScene(sceneName);

				if (!scene)
					CONDITIONAL_THROW("Invalid location: Scene " + sceneName +
						"does not exist in " + currentNode->name());

				return scene;

#undef CONDITIONAL_THROW
			}

			void Destination::relative(bool r)
			{
				mRelative = r;
			}

			void Destination::write(Writer* writer)
			{
				assert(writer);
				writer->push("destination", { {"backsteps",	toString(mBacksteps)},
				                              {"relative", mRelative ? "1":"0"} });
				for (auto it = mLocationChain.begin(); it != mLocationChain.end() - 1; ++it)
				{
					writer->push("link");
					writer->writeBytes(*it);
					writer->pop();
				}
				writer->pop();
			}
		}
	}
}