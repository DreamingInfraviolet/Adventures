#ifndef VIRTUALTILEGRID_H
#define VIRTUALTILEGRID_H
#include "rectangle.h"
#include "pixelrgba.h"
#include <vector>

#include "tile.h"
#include "matrixd.h"

/**
 * This class is used to refer to a grid of tiles. As
 * the real grid may contain holes and is composed of a multitude
 * of tiles, it can be inconvenient to do basic 2D pixel manipulation.
 * This class is meant to abstract the system, acting as a 2D array of
 * pixels while hiding the underlying implementation. Should be a little
 * efficient.
 * */

class World;
class Layer;

typedef void VTFIterFunc(anima::graphics::Tile*);

class VirtualTileGrid
{
World* mWorld;
Layer* mLayer;
Rectanglef mRect;
std::vector<std::vector<anima::graphics::Tile*> > mTileGrid;
math::vec2i startGridIndex, endGridIndex, gridSize, startPixels; //world indices for grids. [start,end)
math::vec2i mSize;

friend class IntermediaryAccessClass;

public:

    int width() {return mSize.x;}
    int height() {return mSize.y;}

    void iterate(VTFIterFunc Func)
    {
        for(auto it1 = mTileGrid.begin(); it1!=mTileGrid.end(); ++it1)
            for(auto it2 = it1->begin(); it2!=it1->end(); ++it2)
                Func(*it2);
    }

    void upload()
    {
        iterate([] (anima::graphics::Tile* tile) {tile->upload();});
    }

    //takes in the world, and a rectangle that represents the location
    //of the virtual image. Tiles are created as needed.
    VirtualTileGrid(World* world, const Rectanglef& rectangle, Layer* layer);

    class IntermediaryAccessClass
    {
        int xCoord;
        VirtualTileGrid* mParent;

    public:

        IntermediaryAccessClass(int xCoord_, VirtualTileGrid* parent)
            : xCoord(xCoord_), mParent(parent) {}

        PixelRGBA& operator [] (int yCoord);
    };


    IntermediaryAccessClass operator [] (int location);

};

#endif // VIRTUALTILEGRID_H
