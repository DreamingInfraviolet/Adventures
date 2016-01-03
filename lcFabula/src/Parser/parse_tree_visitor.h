#pragma once

namespace fabula
{
    namespace parsing
    {
        namespace node
        {
            class Scene;
            class Section;
            class String;
            class Header;
            class Destination;
            class Choice;
        }

        class ParseTreeVisitor
        {
            public:
                virtual void visit(node::Scene& in) = 0;
                virtual void visit(node::Section& in) = 0;
                virtual void visit(node::String& in) = 0;
                virtual void visit(node::Header& in) = 0;
                virtual void visit(node::Destination& in) = 0;
                virtual void visit(node::Choice& in) = 0;
        };
    }
}