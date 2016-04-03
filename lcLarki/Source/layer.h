#ifndef LAYER_H
#define LAYER_H

#include "sprite.h"

typedef std::map<math::vec2i, anima::graphics::ISprite> TileContainer;

class Layer
{

public:
    Layer();

    TileContainer mTiles;

	anima::graphics::ISprite* getTile(const math::vec2i& index);

    bool tileExists(const math::vec2i& index)
    {
        return mTiles.count(index) > 0;
    }

	anima::graphics::ISprite* createTile(const math::vec2i& index, int resolution);
};

#endif // LAYER_H
