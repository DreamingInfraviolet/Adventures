#ifndef CURSOR_H
#define CURSOR_H
#include "matrixd.h"
#include "imagegpu.h"

class Cursor
{
math::vec2 mGlobalPos;
ImageGPU mImage;

public:
    explicit Cursor();
    void globalPos(const math::vec2& normalisedScreenPos, const math::mat3& cameraMatrix);
    math::vec2 globalPos() const;
    void draw(const math::mat3 &cameraMatrix);
};

#endif // CURSOR_H
