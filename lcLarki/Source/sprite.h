#ifndef SPRITE_H
#define SPRITE_H

#include "imagegpu.h"
#include "matrixd.h"

template <class CoordType>
class Sprite : public ImageGPU
{
private:
    math::tmp::_vec2<CoordType> mPos;
public:
    Sprite();


};

#endif // SPRITE_H
