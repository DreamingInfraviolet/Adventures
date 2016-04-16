#pragma once
#include "canvas_view_visitor.h"
#include "shaderprogram.h"
class CanvasView;

class OperationRender : public CanvasViewVisitor
{
public:
	CanvasView* canvasView;

	virtual ~OperationRender() {};

	virtual void visit(CanvasView* view) override;
	virtual void visit(anima::graphics::ISprite* tile) override;
};