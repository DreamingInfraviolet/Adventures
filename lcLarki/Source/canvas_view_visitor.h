#pragma once
#include "canvas_visitor.h"
#include "canvas_view.h"

class CanvasViewVisitor : public CanvasVisitor
{
public:
	virtual ~CanvasViewVisitor() {};

	virtual void visit(CanvasView* view)
	{
		this->CanvasVisitor::visit(&view->mCanvas);
	}
};