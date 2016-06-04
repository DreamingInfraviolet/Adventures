#pragma once
#include "camera.h"
#include "mainshader.h"
#include "canvas.h"

class CanvasView
{
	int mCurrentLayer;

public:
	Camera mCamera;
	Canvas& mCanvas;
	MainShader* shader;
	CanvasView(Canvas& canvas, MainShader* shader)
		: mCurrentLayer(0), mCanvas(canvas), shader(shader)
	{
		mCamera.zoom(2.f);
	}

	Layer& currentLayer() { return mCanvas.mLayers[mCurrentLayer]; }

	void zoom(float amount)
	{
		mCamera.zoom(mCamera.zoom() + amount);
	}

	void pan(float x, float y)
	{
		mCamera.position(mCamera.position() + math::vec2(x, y));
	}

	void resizeViewport(int w, int h)
	{
		mCamera.aspect(float(w) / h);
	}
};