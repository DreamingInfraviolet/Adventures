#ifndef CANVAS_H
#define CANVAS_H
#include "camera.h"
#include "world.h"

class Canvas
{
private:
    World mWorld;

public:
    Canvas();
    Camera mCamera;

    /**Zooms into the canvas by a set amount delta.*/
    void zoom(float amount);

    /**Pans the canvas by the deltas received in normalized units.*/
    void pan(float x, float y);

    /**Draws the canvas.*/
    void draw();

    /**Performs changes necessary after resizing.*/
    void resizeViewport(int w, int h);

    void applyBrush(const math::vec2& worldPos);
};

#endif // CANVAS_H
