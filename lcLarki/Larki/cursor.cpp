#include "cursor.h"
#include "glwidget.h"

Cursor::Cursor()
{
    mImage.setSize(2,2);
    mImage.fill(PixelARGB(0,255,0));
    mImage.upload();
}

//Sets the world position of the cursor.
void Cursor::globalPos(const math::vec2& normalisedScreenPos, const math::mat3& cameraMatrix)
{
    mGlobalPos = (cameraMatrix.getInverse()*math::vec3(normalisedScreenPos,1)).xy();
}


void Cursor::draw(const math::mat3& cameraMatrix)
{
    mImage.set();

    gGLWidget->shader().setTransformMatrix(cameraMatrix*math::mat3(0.01,0,mGlobalPos.x,
                                                                       0,0.01,mGlobalPos.y,
                                                                       0,0,1));

    gGLWidget->drawWithState();
}


math::vec2 Cursor::globalPos() const
{
    return mGlobalPos;
}
