#ifndef MAINSHADER_H
#define MAINSHADER_H
#include "shaderprogram.h"
#include "matrixd.h"

class MainShader : public ShaderProgram
{
private:
    int mTransformMatrixID;
    int mDiffuseID;

public:
    MainShader();

    virtual void prepare () override;

    void setTransformMatrix(const math::mat3& matrix);
};

#endif // MAINSHADER_H
