#include "visitor_semantic_checker.h"
#include "parse_nodes.h"
#include <cassert>

namespace fabula
{
    namespace parsing
    {
        void VisitorSemanticChecker::visit(node::Scene& in)
        {
			visit(in.header());
			if (in.choices())
				for (node::Choice* choice : *in.choices())
				{
					assert(choice);
					visit(*choice);
				}

			if (in.destination())
				visit(*in.destination());
        }

        void VisitorSemanticChecker::visit(node::Section& in)
        {
            //In this rather unique scenario, the semantics are guaranteed to be already checked
            //due to how the values are stored in a map for efficiency and were checked beforehand ^.^
            //We only need to visit the other nodes.

            for (auto it = in.scenesBegin(); it != in.scenesEnd(); ++it)
            {
                assert(it->second);
                visit(*it->second);
            }
            for (auto it = in.sectionsBegin(); it != in.sectionsEnd(); ++it)
            {
                assert(it->second);
                visit(*it->second);
            }
        }

        void VisitorSemanticChecker::visit(node::String& in)
        {

        }

        void VisitorSemanticChecker::visit(node::Header& in)
        {
			visit(in.title());
			visit(in.description());
        }

        void VisitorSemanticChecker::visit(node::Destination& in)
        {
            in.getScene(true);
        }

        void VisitorSemanticChecker::visit(node::Choice& in)
        {
			visit(in.header());
			visit(in.destination());
        }
    }
}