#pragma once
#include "camera.h"
#include "mainshader.h"
#include "layer.h"

class Canvas
{
private:
	int mTileResolution;

public:
	std::vector<Layer> mLayers;
    Canvas();

	int layerCount() const;
	Layer& createLayer();
	Layer& getLayer(int index);
	void deleteLayer(int index);

	void clear();

	int tileResolution();
};