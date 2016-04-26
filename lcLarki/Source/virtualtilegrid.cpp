#include "stdafx.h"
#include "virtualtilegrid.h"
#include "layer.h"
#include "io.h"
#include "canvas.h"
#include "canvas_helper.h"

using namespace canvas_helper;

VirtualTileGrid::VirtualTileGrid(Layer& layer, const util::Rectanglef &rectangle, int tileResolution)
    : mLayer(layer), tileResolution(tileResolution), mRect(rectangle)
{
	float fTileResolution = (float)tileResolution;
    startGridIndex = getTileIndex(math::vec2(rectangle.leftEdge(),rectangle.bottomEdge()));
    endGridIndex = getTileIndex(math::vec2(rectangle.rightEdge(),rectangle.topEdge()))+1;
    gridSize = endGridIndex-startGridIndex;

    mSize = math::vec2i((int)(rectangle.w()*fTileResolution),(int)(rectangle.h()*fTileResolution));

    startPixels = getCoordinatesInTile(math::vec2(mRect.x(),mRect.y()), startGridIndex, fTileResolution);

    mTileGrid.resize(gridSize.x);
    for(size_t x = 0; x < mTileGrid.size(); ++x)
    {
        mTileGrid[x].reserve(gridSize.y);
        for(int y = 0; y < gridSize.y; ++y)
            mTileGrid[x].push_back(layer.createTile(startGridIndex+math::vec2i(x,y), fTileResolution));
    }
}

uint32_t* VirtualTileGrid::getPixel (int xCoord, int yCoord)
{
    math::vec2i coordsWithOffset = startPixels+math::vec2i(xCoord,yCoord);

    math::vec2i tile = coordsWithOffset/tileResolution;
    math::vec2i pixelPos = coordsWithOffset % tileResolution;

    return mTileGrid[tile.x][tile.y]->getPixelRef(pixelPos.x, pixelPos.y);

}

void VirtualTileGrid::upload()
{
	for (auto& a : mTileGrid)
		for (auto& b : a)
			b->upload();
}
