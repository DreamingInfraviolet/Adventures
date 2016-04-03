#include "stdafx.h"
#include "canvas.h"
#include "glwidget.h"
#include "rectangle.h"
#include "virtualtilegrid.h"
#include "io.h"
#include "layer.h"

Canvas::Canvas()
{
	mTileResolution = 256;
	mLayers.push_back(Layer());
}

int Canvas::layerCount() const { return (int)mLayers.size(); }
Layer& Canvas::createLayer() { mLayers.push_back(Layer()); return mLayers.back(); }
Layer& Canvas::getLayer(int index) { return mLayers[index]; }
void Canvas::deleteLayer(int index) { mLayers.erase(mLayers.begin() + index); }
void Canvas::clear() { mLayers.clear(); }
int Canvas::tileResolution() { return mTileResolution; }

