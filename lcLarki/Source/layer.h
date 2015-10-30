#ifndef LAYER_H
#define LAYER_H

#include <map>
#include "tile.h"
#include "matrixd.h"

typedef std::map<math::vec2i, anima::graphics::Tile> TileContainer;

class Layer
{
    TileContainer mTiles;

public:
    Layer();

    TileContainer& tiles()
    {
        return mTiles;
    }

	anima::graphics::Tile* getTile(const math::vec2i& index);

    bool tileExists(const math::vec2i& index)
    {
        return (bool)mTiles.count(index);
    }

	anima::graphics::Tile* createTile(const math::vec2i& index, int resolution);

    static void uploadTile(anima::graphics::Tile* tile)
    {
        tile->upload();
    }
};

#endif // LAYER_H
