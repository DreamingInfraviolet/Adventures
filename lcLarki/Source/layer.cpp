#include "stdafx.h"
#include "layer.h"

Layer::Layer()
{

}

anima::graphics::ISprite* Layer::createTile(const math::vec2i& index, int resolution)
{
    auto it = mTiles.find(index);

    //if tile does not exist, create it.
    if(it==mTiles.end())
    {
		anima::graphics::ISprite tile;
        tile.setSize(resolution, resolution);
        tile.fill(0,0,0,0);

        tile.upload();
        auto newIterator = mTiles.insert(std::make_pair(index, std::move(tile))).first;
        return &(newIterator->second);
    }
    else
    {
        return &(it->second);
    }
}

anima::graphics::ISprite* Layer::getTile(const math::vec2i& index)
{
    auto it = mTiles.find(index);
    if(it==mTiles.end())
        return nullptr;
    else
        return &it->second;
}
