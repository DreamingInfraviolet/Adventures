#pragma once
#include <io.h>

/**A virtual base class to give essential shader creation functionality to derived classes.*/
class ShaderProgram
{
private:
    GLuint m_vert = 0;
    GLuint m_frag = 0;

protected:
    GLuint m_id = 0;

    /**Performs shader-specific setup. Override, but don't call directly.*/
    virtual void prepare() {} //called from within load(...) function.
public:

    /**Returns the ID of the shader.*/
    GLint id() const { return m_id; }

    /**
    Initialises the shader from a source file.
    @param vertpath The part of the vertex shader.
    @param fragpath The path of the fragment shader.
    @return The success value.
    */
	bool load(const std::string& vertpath, const std::string& fragpath);

    /**Checks whether the shader is working properly.*/
    bool validate();

    /**The virtual destructor to do basic cleanup.*/
    virtual ~ShaderProgram();

    /**Sets the shader as the current one in the rendering pipeline.*/
    void set();
};