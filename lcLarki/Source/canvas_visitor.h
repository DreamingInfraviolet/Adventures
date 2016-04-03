#pragma once
#include "canvas.h"
#include "layer.h"
#include "sprite.h"

class CanvasVisitor
{
public:
	virtual void visit(Canvas* canvas)
	{
		for (auto itLayer = canvas->mLayers.begin(); itLayer != canvas->mLayers.end(); ++itLayer)
			visit(&*itLayer);
	}

	virtual void visit(Layer* layer)
	{
		for (auto itTile = layer->mTiles.begin(); itTile != layer->mTiles.end(); ++itTile)
			visit(&itTile->second);
	}

	virtual void visit(anima::graphics::ISprite* tile)
	{

	}
};