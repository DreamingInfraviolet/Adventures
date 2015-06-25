#include "canvas.h"
#include "glwidget.h"

Canvas::Canvas()
{
    mCamera.zoom(2.f);
}

void Canvas::zoom(float amount)
{
    mCamera.zoom(mCamera.zoom()+amount);
}

void Canvas::pan(float x, float y)
{
    mCamera.position(mCamera.position()+math::vec2(x,y));
}

void Canvas::draw()
{
    //problem with iterator: returns result when no tiles exist.

    for(auto it = mWorld.begin(); it!=mWorld.end(); ++it)
    {
        math::vec2i tilePos = it.get().first;
        Tile* tile = it.get().second;
        tile->set();

        gGLWidget->shader().setTransformMatrix(mCamera.matrix() * math::mat3(0.5f,0,tilePos.x,
                                                                             0,0.5f,tilePos.y,
                                                                             0,0,1));

        gGLWidget->drawWithState();
    }
}

void Canvas::resizeViewport(int w, int h)
{
    mCamera.aspect(float(w)/h);
}


void Canvas::applyBrush(const math::vec2& worldPos)
{
    mWorld.applyBrush(worldPos, 0.2f);
}
