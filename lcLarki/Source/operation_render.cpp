#include "stdafx.h"
#include "operation_render.h"
#include "canvas_view.h"

void OperationRender::visit(CanvasView* view)
{
	canvasView = view;
	CanvasViewVisitor::visit(view);
}

void OperationRender::visit(anima::graphics::ISprite* tile)
{
	math::vec2i tilePos = tile->mPos;
	tile->set();

	canvasView->shader->setTransformMatrix(canvasView->mCamera.matrix() * math::mat3(0.5f, 0, tilePos.x,
		0, 0.5f, tilePos.y,
		0, 0, 1));

	glDrawArrays(GL_TRIANGLES, 0, 6);
}
