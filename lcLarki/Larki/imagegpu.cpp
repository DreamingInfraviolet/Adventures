#include "imagegpu.h"
#include "io.h"
#include <QOpenGLTexture>
//#define GLERROR { unsigned err = glGetError(); std::ostringstream str1, str2; str1<<err; str2<<__LINE__; if (err!=0) {Error(std::string("GL Error ") + (str1).str() + " at line " + (str2).str() +"\n" + __FILE__ + "\n");}}

ImageGPU::ImageGPU() : Image()
{
    mWidth = 0;
    mHeight = 0;
    mUploaded = false;
    mTexture = nullptr;
}


void ImageGPU::upload()
{
    deupload();
    if(mPixels.size()==0)
        return;
    mTexture = new QOpenGLTexture(QImage((uchar*)&mPixels[0], mWidth, mHeight,
                                  mWidth*sizeof(PixelARGB), QImage::Format_ARGB32));
    mTexture->setMinificationFilter(QOpenGLTexture::NearestMipMapNearest);
    mTexture->setMagnificationFilter(QOpenGLTexture::Nearest);
    mTexture->setWrapMode(QOpenGLTexture::ClampToEdge);
}

void ImageGPU::deupload()
{
    if(mTexture)
        delete mTexture;
}

void ImageGPU::set()
{
    if(mTexture==nullptr)
        Error("Attempting to bind uninitialised texture.");
    mTexture->bind();
}
