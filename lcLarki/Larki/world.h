#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "layer.h"

class World
{
private:
    int mTileResolution;
    std::vector<Layer> mLayers;
    ImageGPU mImage;
    int mCurrentLayer;

public:
    World();

    int layerCount() const;
    Layer& createLayer();
    Layer& getLayer(int index);
    void deleteLayer(int index);
    void clear();

    math::vec2i getCoordinatesInTile(const math::vec2& worldPos, const math::vec2i& tileIndex) const;
    math::vec2i getTileIndex(math::vec2 worldPos) const;

    int tileResolution();

    void applyBrush(const math::vec2& worldPos, float radius);

    //iterates through all the image tiles.
    class iterator
    {
    private:
        std::vector<Layer>::iterator layerEndIterator; //end() layer iterator
        std::vector<Layer>::iterator layerIterator; //layer iterator points to laye
        TileContainer::iterator layerTileIterator; //iterator in current tile map
        bool end;

    public:

        iterator();
        iterator(const std::vector<Layer>::iterator& layerIter,
                 const std::vector<Layer>::iterator& layerEndIter,
                 const TileContainer::iterator& tileIter);

        //returns tile position -> tile
        std::pair<math::vec2i, Tile*> get();


        iterator& operator++();

        iterator operator++(int);

        bool operator==(const iterator& iter);

        bool operator!=(const iterator& iter);

    };

    iterator begin();

    iterator end() const;
};

#endif // WORLD_H
