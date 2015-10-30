#include "world.h"
#include "rectangle.h"
#include "virtualtilegrid.h"
#include <math.h>
#include "io.h"

World::World()
{
    mTileResolution = 256;
    mCurrentLayer=0;
    mLayers.push_back(Layer());

}


int World::layerCount() const { return (int)mLayers.size(); }
Layer& World::createLayer() { mLayers.push_back(Layer()); return mLayers.back(); }
Layer& World::getLayer(int index) { return mLayers[index]; }
void World::deleteLayer(int index) { mLayers.erase(mLayers.begin() + index); }

void World::clear() { mLayers.clear(); }

math::vec2i World::getTileIndex(math::vec2 worldPos) const
{
    worldPos += 0.5f;

    return math::vec2i((int)floor(worldPos.x), (int)floor(worldPos.y));
}

int World::tileResolution()
{
    return mTileResolution;
}

math::vec2i World::getCoordinatesInTile(const math::vec2& worldPos, const math::vec2i& tileIndex) const
{
    return math::vec2i(
        ((worldPos.x+0.5f) - tileIndex.x)* mTileResolution,
        ((worldPos.y+0.5f) - tileIndex.y)* mTileResolution) ;
}

void World::applyBrush(const math::vec2& worldPos, float radius)
{
    VirtualTileGrid vtg(this, Rectanglef(worldPos,radius), &mLayers[mCurrentLayer]);

//    for(int x = 0; x < vtg.width(); ++x)
//        for (int y = 0; y < vtg.height(); ++y)
//            vtg[x][y]=PixelARGB(255,255,255);

    math::vec2i middle = math::vec2i(vtg.width(), vtg.height())/2;
        for(int x = 0; x < vtg.width(); ++x)
            for (int y = 0; y < vtg.height(); ++y)
            {
                int radius = 128;
                auto d = math::vec2i(x,y).distanceSquared(middle);
                PixelRGBA pixel = d>radius ? PixelRGBA(0):PixelRGBA((255-d*(255.f/(radius)))/20.f);
                pixel.mA = pixel.mR;
                vtg[x][y]+=pixel;
            }

    vtg.upload();
}