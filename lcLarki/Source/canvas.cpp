#include "canvas.h"
#include "glwidget.h"
#include <GL/glew.h>

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

void Canvas::draw(MainShader& shader)
{
	for (auto itLayer = mWorld.mLayers.begin(); itLayer != mWorld.mLayers.end(); ++itLayer)
    {
		for (auto itTile = itLayer->tiles().begin(); itTile != itLayer->tiles().end(); ++itTile)
		{
			math::vec2i tilePos = itTile->first;
			anima::graphics::Tile& tile = itTile->second;
			tile.set();

			shader.setTransformMatrix(mCamera.matrix() * math::mat3(0.5f, 0, tilePos.x,
				0, 0.5f, tilePos.y,
				0, 0, 1));

			glDrawArrays(GL_TRIANGLES, 0, 6);
		}
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
