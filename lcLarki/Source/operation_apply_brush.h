#pragma once
#include "canvas_visitor.h"
#include "shaderprogram.h"
#include "virtualtilegrid.h"

class CanvasView;

class OperationApplyBrush : public CanvasVisitor
{
	int tileResolution;
public:
	CanvasView* canvasView;
	math::vec2 worldPos;
	float radius;

	OperationApplyBrush()
		: worldPos(worldPos), radius(radius) {}

	virtual void visit(Canvas* canvas) override
	{
		tileResolution = canvas->tileResolution();
		CanvasVisitor::visit(canvas);
	}

	virtual void visit(Layer* layer) override
	{
		VirtualTileGrid vtg(*layer, util::Rectanglef(worldPos, radius), tileResolution);

		//    for(int x = 0; x < vtg.width(); ++x)
		//        for (int y = 0; y < vtg.height(); ++y)
		//            vtg[x][y]=PixelARGB(255,255,255);

		math::vec2i middle = math::vec2i(vtg.width(), vtg.height()) / 2;
		for (int x = 0; x < vtg.width(); ++x)
			for (int y = 0; y < vtg.height(); ++y)
			{
				auto d = math::vec2i(x, y).distanceSquared(middle);
				uint32_t pixel = d>radius ? 0u:~0u;
				*vtg.getPixel(x,y)=pixel;
			}

		vtg.upload();
	}
};