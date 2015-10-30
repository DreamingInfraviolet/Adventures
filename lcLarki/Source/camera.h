#ifndef CAMERA_H
#define CAMERA_H
#include "matrixd.h"
#include "io.h"

class Camera
{
    math::vec2 mPos;

    //closeness=1/zoom.
    float mZoom, mAspect;
    math::mat3 mMatrix;
    float mMinZoom;
    float mMaxZoom;
    bool mMatrixUpdateFlag;
public:
    Camera();

    /**Sets the zoom of the camera. Appearance = object*zoom. */
    void zoom(float z);

    /**Returns the zoom of the camera. Appearance = object*zoom. */
    float zoom() const;

    /**Sets the aspect ration of the camera.*/
    void aspect(float a);

    /**Returns the aspect ration of the camera.*/
    float aspect() const;

    /**Returns the position of the camera.*/
    math::vec2 position() const;

    /**Sets the position of the camera.*/
    void position(const math::vec2& pos);

    /**Returns or generates a matrix for the camera.*/
    math::mat3 matrix();

    /**Forces the matrix to be regenerated.*/
    void generateMatrix();
};

#endif // CAMERA_H
