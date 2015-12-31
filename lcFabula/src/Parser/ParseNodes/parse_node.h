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

                enum class NodeType { Section, Scene, Choice, Destination, String };

                /** Returns the corresponding node type of the class. */
                virtual NodeType nodeType() = 0;

                /** Notifies all children that this is the parent, and calls bindChildren on them. */
                virtual void bindChildren() = 0;

                /** Performs semantic error detection, throwing an exception if failed. */
                virtual void checkSemantics() = 0;

            protected:

                // The parent, if any.
                ParaseNode* parent = nullptr;
            }; 
        }
    }
}