#include "mainshader.h"
#include "glwidget.h"

MainShader::MainShader()
{
    mTransformMatrixID=-1;
    mDiffuseID=-1;
}

void MainShader::prepare ()
{
    set();
    gGLWidget->glBindAttribLocation(m_id, 0, "vertuv");
    mTransformMatrixID = gGLWidget->glGetUniformLocation(m_id, "transformMatrix");
    mDiffuseID = gGLWidget->glGetUniformLocation(m_id, "diffuse");
    gGLWidget->glUniform1i(mDiffuseID, 0);
}

void MainShader::setTransformMatrix(const math::mat3& matrix)
{
    gGLWidget->glUniformMatrix3fv(mTransformMatrixID, 1, GL_FALSE,&matrix.m[0][0]);
}


