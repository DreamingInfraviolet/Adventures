#pragma once

/**
  * @author Anima Seteine
  * @purpose This is an abstract class inherited from by every parse node that is used during the parse stage.
  *          It defines the functionality that each node must have, helping the transition into successive stages.
  */

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            class ParseNode
            {
            public:

                enum class NodeType { Section, Scene, Choice, Destination, String, Header };

                /** Returns the corresponding node type of the class. */
                virtual NodeType nodeType() = 0;

                /** Sets the parent of the object and prompts it to set itself as a parent to its children. */
				void bindParent(ParseNode* parent)
				{
					mParent = parent;
					bindChildren();
				}

				/** Calls bindParent on all its children. */
				virtual void bindChildren() = 0;

                /** Performs semantic error detection, throwing an exception if failed. */
                virtual void checkSemantics() = 0;

			private:
                // The parent, if any.
				ParseNode* mParent = nullptr;

			public:

				ParseNode* parent() { return mParent; }

            }; 
        }
    }
}