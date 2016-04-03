#include "stdafx.h"
#include "image.h"
#include "io.h"

namespace anima
{
	namespace graphics
	{
		Image::Image() : mWidth(0), mHeight(0), mPixels(nullptr)
		{
		}

		Image::Image(int sizex, int sizey) : Image()
		{
			setSize(sizex, sizey);
		}

		Image::~Image()
		{
			delete mPixels;
		}

		void Image::setSize(int sizex, int sizey)
		{
			delete mPixels;
			mWidth = sizex;
			mHeight = sizey;
			mPixels = new uint32_t[sizex*sizey];
			
		}

		void Image::fill(const uint8_t r, uint8_t g, uint8_t b, uint8_t a)
		{
			if (!mPixels)
				return;

			uint32_t px = 0;
			px |= a;
			px |= b << 8;
			px |= g << 16;
			px |= r << 24;
			size_t totalSize = mWidth*mHeight*sizeof(uint32_t);
			memset(mPixels, px, totalSize);
		}

		void Image::setPixel(const int x, const int y, const uint32_t colour)
		{
			mPixels[x + y*mWidth] = colour;
		}

		uint32_t* Image::getPixelRef(const uint32_t x, const uint32_t y)
		{
			return mPixels + x + y*mWidth;
		}

		int Image::height() const
		{
			return mHeight;
		}

		int Image::width() const
		{
			return mWidth;
		}
	}
}