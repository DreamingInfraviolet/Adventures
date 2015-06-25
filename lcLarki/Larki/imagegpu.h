#ifndef IMAGEGPU_H
#define IMAGEGPU_H
#include "image.h"


class QOpenGLTexture;


class ImageGPU : public Image
{
    QOpenGLTexture* mTexture;
    bool mUploaded;

public:

    ImageGPU();

    void upload();

    void deupload();

    void set();
};

#endif // IMAGEGPU_H
