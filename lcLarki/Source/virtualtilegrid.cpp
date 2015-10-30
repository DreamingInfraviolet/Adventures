#include "virtualtilegrid.h"
#include "world.h"
#include "layer.h"
#include <math.h>
#include "io.h"
#include "pixelrgba.h"

//tile size: 1, or 100 pixels.
//brush size: d=2.4,or d=240 pixels.

VirtualTileGrid::VirtualTileGrid(World *world, const Rectanglef &rectangle, Layer* layer)
    : mWorld(world), mRect(rectangle), mLayer(layer)
{
    startGridIndex = world->getTileIndex(math::vec2(rectangle.leftEdge(),rectangle.bottomEdge()));
    endGridIndex = world->getTileIndex(math::vec2(rectangle.rightEdge(),rectangle.topEdge()))+1;
    gridSize = endGridIndex-startGridIndex;

    mSize = math::vec2i((int)(rectangle.w()*mWorld->tileResolution()),(int)(rectangle.h()*mWorld->tileResolution()));

    startPixels = mWorld->getCoordinatesInTile(math::vec2(mRect.x(),mRect.y()), startGridIndex);


    mTileGrid.resize(gridSize.x);
    for(size_t x = 0; x < mTileGrid.size(); ++x)
    {
        mTileGrid[x].reserve(gridSize.y);
        for(int y = 0; y < gridSize.y; ++y)
            mTileGrid[x].push_back(mLayer->createTile(startGridIndex+math::vec2i(x,y), world->tileResolution()));
    }
}


VirtualTileGrid::IntermediaryAccessClass VirtualTileGrid::operator [] (int location)
{
    return IntermediaryAccessClass(location, this);
}

PixelRGBA& VirtualTileGrid::IntermediaryAccessClass::operator [] (int yCoord)
{
    math::vec2i coordsWithOffset = mParent->startPixels+math::vec2i(xCoord,yCoord);

    math::vec2i tile = coordsWithOffset/mParent->mWorld->tileResolution();
    math::vec2i pixelPos = coordsWithOffset % mParent->mWorld->tileResolution();

    return mParent->mTileGrid[tile.x][tile.y]->getPixelRef(pixelPos.x, pixelPos.y);
}
