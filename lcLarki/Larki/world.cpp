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

World::World();

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
                PixelARGB pixel = d>radius ? PixelARGB(0):PixelARGB((255-d*(255.f/(radius)))/20.f);
                pixel.mA = pixel.mR;
                vtg[x][y]+=pixel;
            }

    vtg.upload();
}


    World::iterator::iterator()
    {
        end=true;
    }

    World::iterator::iterator(const std::vector<Layer>::iterator& layerIter,
             const std::vector<Layer>::iterator& layerEndIter,
             const TileContainer::iterator& tileIter)
    :
        layerEndIterator(layerEndIter),
        layerIterator(layerIter),
        layerTileIterator(tileIter),
        end(false)
    {}

    //returns tile position -> tile
    std::pair<math::vec2i, Tile*> World::iterator::get()
    {
        if(end)
            return {};
        return std::make_pair(layerTileIterator->first, &layerTileIterator->second);
    }


    World::iterator& World::iterator::operator++()
    {
        if(end)
            return *this;

        ++layerTileIterator;
        //If no tiles left in current layer
        if(layerTileIterator == layerIterator->tiles().end())
        {
            do
            {
                ++layerIterator;
            } while(layerIterator!=layerEndIterator && layerIterator->tiles().size()==0);

            //if no more layers.
            if(layerIterator == layerEndIterator)
            {
                end = true;
            }
            else
            {
                layerTileIterator = layerIterator->tiles().begin();
            }
        }

        return *this;
    }

    World::iterator World::iterator::operator++(int)
    {
        iterator current = *this;
        ++*this;
        return current;
    }

    bool World::iterator::operator==(const iterator& iter)
    {
        if(end==iter.end)
            return true;
        else
        {
            return layerIterator == iter.layerIterator &&
                   layerTileIterator == iter.layerTileIterator;
        }
    }

    bool World::iterator::operator!=(const iterator& iter)
    {
        return !(*this==iter);
    }


World::iterator World::begin()
{
    auto startingLayer = mLayers.begin();
    while(startingLayer!=mLayers.end() && startingLayer->tiles().size()==0)
        ++startingLayer;

    if(startingLayer==mLayers.end())
        return end();
    else
        return iterator (startingLayer, mLayers.end(), startingLayer->tiles().begin());
}

World::iterator World::end() const
{
    return iterator();
}

