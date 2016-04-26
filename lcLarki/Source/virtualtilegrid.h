#pragma once
#include "rectangle.h"
#include "sprite.h"
#include "matrixd.h"

/**
 * This class is used to refer to a grid of tiles. As
 * the real grid may contain holes and is composed of a multitude
 * of tiles, it can be inconvenient to do basic 2D pixel manipulation.
 * This class is meant to abstract the system, acting as a 2D array of
 * pixels while hiding the underlying implementation.
 * It's designed to be lightweight, and instantiation only exists to precompute some tasks.
 * Upon creation, it fills up any holes inside the rectangle. So only really use this if you're going to use most of the pixels inside it.
 * */

class World;
class Layer;

typedef void VTFIterFunc(anima::graphics::ISprite*);

class VirtualTileGrid
{
	//Many of these don't seem to be used. Investigate later ^^
	Layer& mLayer;
	int tileResolution;
	util::Rectanglef mRect;
	std::vector<std::vector<anima::graphics::ISprite*> > mTileGrid;
	math::vec2i startGridIndex, endGridIndex, gridSize, startPixels; //world indices for grids. [start,end)
	math::vec2i mSize;

public:

    int width() {return mSize.x;}
    int height() {return mSize.y;}

    //takes in the world, and a rectangle that represents the location
    //of the virtual image. Tiles are created as needed.
    VirtualTileGrid(Layer& layer, const util::Rectanglef &rectangle, int tileResolution);

    uint32_t* getPixel(int x, int y);

	void upload();
};