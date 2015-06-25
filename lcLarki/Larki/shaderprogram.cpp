#include "shaderprogram.h"
#include "glwidget.h"
#include <QGLWidget>
#include <fstream>

bool ShaderProgram::validate()
{
    GLint valstatus;
    gGLWidget->glValidateProgram(m_id);
    gGLWidget->glGetProgramiv(m_id, GL_VALIDATE_STATUS, &valstatus);
    if (!valstatus)
    {
        GLint length;
        gGLWidget->glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &length);
        char* log = new char[length];
        gGLWidget->glGetProgramInfoLog(m_id, length, NULL, log);
        Error(std::string("Error validating program:") + log);
        delete[] log;
        return false;
    }
    return true;
}

bool ShaderProgram::load(const std::string& vertpath, const std::string& fragpath)
{
    using namespace std;
    Inform (std::string("Making shader: ") + (vertpath) + ", " +
        (fragpath));
    fstream fragfile(fragpath, ios::in | ios::ate), vertfile(vertpath, ios::in | ios::ate);
    const unsigned fragsize = (unsigned)fragfile.tellg(), vertsize = (unsigned)vertfile.tellg();
    fragfile.seekg(0);
    vertfile.seekg(0);
    if (vertfile.fail() || vertsize == 0)
    {
        Warning(string("Could not open ") + vertpath);
        return false;
    }
    if (fragfile.fail() || fragsize == 0)
    {
        Warning(string("Could not open ") + fragpath + "!");
        return false;
    }

    string vertstr, fragstr, temp;
    while (getline(vertfile, temp))
        vertstr += temp + "\n";
    while (getline(fragfile, temp))
        fragstr += temp + "\n";
    fragfile.close();
    vertfile.close();
    GLuint frag = gGLWidget->glCreateShader(GL_FRAGMENT_SHADER);
    GLuint vert = gGLWidget->glCreateShader(GL_VERTEX_SHADER);
    const char* fragPointer = fragstr.c_str();
    const char* vertPointer = vertstr.c_str();

    gGLWidget->glShaderSource(frag, 1, &fragPointer, NULL);
    gGLWidget->glShaderSource(vert, 1, &vertPointer, NULL);
    GLsizei logLength;
    GLint result;
    gGLWidget->glCompileShader(frag);
    gGLWidget->glGetShaderiv(frag, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        gGLWidget->glGetShaderiv(frag, GL_INFO_LOG_LENGTH, &logLength);
        char* fragmentShaderErrorMessage = new char[logLength];
        gGLWidget->glGetShaderInfoLog(frag, logLength, NULL, fragmentShaderErrorMessage);
        Warning(string("Error loading fragment shader: ") + fragmentShaderErrorMessage);
        delete[] fragmentShaderErrorMessage;
        return false;
    }

    gGLWidget->glCompileShader(vert);
    gGLWidget->glGetShaderiv(vert, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        gGLWidget->glGetShaderiv(vert, GL_INFO_LOG_LENGTH, &logLength);
        char* vertexShaderErrorMessage = new char[logLength];
        gGLWidget->glGetShaderInfoLog(vert, logLength, NULL, vertexShaderErrorMessage);
        Warning(string("Error loading vertex shader: ") + vertexShaderErrorMessage);
        delete[] vertexShaderErrorMessage;
        return false;
    }
    GLuint prog = gGLWidget->glCreateProgram();
    gGLWidget->glAttachShader(prog, frag);
    gGLWidget->glAttachShader(prog, vert);
    gGLWidget->glLinkProgram(prog);
    gGLWidget->glDeleteShader(frag);
    gGLWidget->glDeleteShader(vert);
    gGLWidget->glGetProgramiv(prog, GL_LINK_STATUS, &result);
    if (!result)
    {
        gGLWidget->glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &logLength);
        char* ProgramErrorMessage = new char[std::max(logLength, int(1))];
        gGLWidget->glGetProgramInfoLog(prog, logLength, NULL, &ProgramErrorMessage[0]);
        Warning(string("Linking error: ") + ProgramErrorMessage);
        delete[] ProgramErrorMessage;
        return false;
    }

    m_frag = frag;
    m_vert = vert;
    m_id = prog;

    prepare();

    if (!validate())
        return false;

    return true;
}

ShaderProgram::~ShaderProgram()
{
    if (m_id)
    {
        if (m_vert)
            gGLWidget->glDetachShader(m_vert, m_id);
        if (m_frag)
            gGLWidget->glDetachShader(m_frag, m_id);
        gGLWidget->glDeleteProgram(m_id);
    }
}

void ShaderProgram::set()
{
    gGLWidget->glUseProgram(m_id);
}
