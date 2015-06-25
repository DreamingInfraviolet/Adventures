#ifndef LAYER_H
#define LAYER_H

#include <map>
#include "tile.h"
#include "matrixd.h"

typedef std::map<math::vec2i, Tile> TileContainer;

class Layer
{
    TileContainer mTiles;

public:
    Layer();

    void clear();
    TileContainer& tiles()
    {
        return mTiles;
    }

    Tile* getTile(const math::vec2i& index);

    bool tileExists(const math::vec2i& index)
    {
        return mTiles.count(index);
    }

    Tile* createTile(const math::vec2i& index, int resolution);

    static void uploadTile(Tile* tile)
    {
        tile->upload();
    }
};

#endif // LAYER_H
