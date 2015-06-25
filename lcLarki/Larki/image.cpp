#include "image.h"

Image::Image() : mWidth(0), mHeight(0)
{
}


Image::Image(int sizex, int sizey) : Image()
{
    setSize(sizex, sizey);
}

void Image::setSize(int sizex, int sizey)
{
    mWidth = sizex;
    mHeight = sizey;
    mPixels.resize(sizex*sizey);
}

void Image::fill(const PixelARGB& colour)
{
    for(unsigned i = 0; i < mPixels.size();++i)
        mPixels[i] = colour;
}

void Image::setPixel(const int x, const int y, const PixelARGB& colour)
{
    mPixels[x+y*mWidth] = colour;
}

PixelARGB& Image::getPixelRef(const int x, const int y)
{
    return mPixels[x+y*mWidth];
}

int Image::height() const
{
    return mHeight;
}

int Image::width() const
{
    return mWidth;
}
