#include "camera.h"

Camera::Camera()
{
    mZoom = 1.f;
    mAspect = 1.f;
    mMinZoom=0.5f;
    mMaxZoom=100.f;
    mMatrixUpdateFlag = true;
}


void Camera::zoom(float z)
{
    if(z>mMaxZoom)
        z=mMaxZoom;
    else if (z<mMinZoom)
        z=mMinZoom;

    mZoom=z;
    mMatrixUpdateFlag=true;
}

float Camera::zoom() const
{
    return mZoom;
}

void Camera::aspect(float a)
{
    mAspect=a;
    mMatrixUpdateFlag=true;
}

float Camera::aspect() const
{
    return mAspect;
}

math::vec2 Camera::position() const
{
    return mPos;
}

void Camera::position(const math::vec2& pos)
{
    mPos = pos;
    mMatrixUpdateFlag = true;
}


math::mat3 Camera::matrix()
{
    if(mMatrixUpdateFlag)
        generateMatrix();
    return mMatrix;
}

void Camera::generateMatrix()
{
    math::mat3 scale =     math::mat3(mZoom*mZoom,0,0,
                                      0,mZoom*mZoom,0,
                                      0,0,1);
    math::mat3 translate = math::mat3(1,0,mPos.x,
                                      0,1,-mPos.y,
                                      0,0,1);
    math::mat3 aspect =    math::mat3(1,0,0,
                                      0,mAspect,0,
                                      0,0,1);

    mMatrix = aspect*translate*scale;

    mMatrixUpdateFlag = false;
}
