#include "stdafx.h"
#include "mainshader.h"
#include "io.h"

MainShader::MainShader()
{
    mTransformMatrixID=-1;
    mDiffuseID=-1;
}

void MainShader::prepare ()
{
    set();
    glBindAttribLocation(m_id, 0, "vertuv");
    mTransformMatrixID = glGetUniformLocation(m_id, "transformMatrix");
    mDiffuseID = glGetUniformLocation(m_id, "diffuse");
    glUniform1i(mDiffuseID, 0);
}

void MainShader::setTransformMatrix(const math::mat3& matrix)
{
    glUniformMatrix3fv(mTransformMatrixID, 1, GL_FALSE,&matrix.m[0][0]);
}


