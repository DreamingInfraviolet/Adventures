#ifndef IMAGE_H
#define IMAGE_H
#include <vector>
#include "pixelargb.h"

class Image
{
protected:
    std::vector<PixelARGB> mPixels;
    int mWidth, mHeight;


public:
    Image();

    Image(int sizex, int sizey);

    void setSize(int sizex, int sizey);

    void fill(const PixelARGB& colour);
    void setPixel(const int x, const int y, const PixelARGB& colour);
    PixelARGB& getPixelRef(const int x, const int y);

    int height() const;
    int width() const;
};

#endif // IMAGE_H
