#include "stdafx.h"
#include "shaderprogram.h"
#include "glwidget.h"
#include "io.h"

bool ShaderProgram::validate()
{
    GLint valstatus;
    glValidateProgram(m_id);
    glGetProgramiv(m_id, GL_VALIDATE_STATUS, &valstatus);
    if (!valstatus)
    {
        GLint length;
        glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &length);
        char* log = new char[length];
        glGetProgramInfoLog(m_id, length, NULL, log);
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
    GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
    GLuint vert = glCreateShader(GL_VERTEX_SHADER);
    const char* fragPointer = fragstr.c_str();
    const char* vertPointer = vertstr.c_str();

    glShaderSource(frag, 1, &fragPointer, NULL);
    glShaderSource(vert, 1, &vertPointer, NULL);
    GLsizei logLength;
    GLint result;
    glCompileShader(frag);
    glGetShaderiv(frag, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        glGetShaderiv(frag, GL_INFO_LOG_LENGTH, &logLength);
        char* fragmentShaderErrorMessage = new char[logLength];
        glGetShaderInfoLog(frag, logLength, NULL, fragmentShaderErrorMessage);
        Warning(string("Error loading fragment shader: ") + fragmentShaderErrorMessage);
        delete[] fragmentShaderErrorMessage;
        return false;
    }

    glCompileShader(vert);
    glGetShaderiv(vert, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        glGetShaderiv(vert, GL_INFO_LOG_LENGTH, &logLength);
        char* vertexShaderErrorMessage = new char[logLength];
        glGetShaderInfoLog(vert, logLength, NULL, vertexShaderErrorMessage);
        Warning(string("Error loading vertex shader: ") + vertexShaderErrorMessage);
        delete[] vertexShaderErrorMessage;
        return false;
    }
    GLuint prog = glCreateProgram();
    glAttachShader(prog, frag);
    glAttachShader(prog, vert);
    glLinkProgram(prog);
    glDeleteShader(frag);
    glDeleteShader(vert);
    glGetProgramiv(prog, GL_LINK_STATUS, &result);
    if (!result)
    {
        glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &logLength);
        char* ProgramErrorMessage = new char[std::max(logLength, int(1))];
        glGetProgramInfoLog(prog, logLength, NULL, &ProgramErrorMessage[0]);
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
            glDetachShader(m_vert, m_id);
        if (m_frag)
            glDetachShader(m_frag, m_id);
        glDeleteProgram(m_id);
    }
}

void ShaderProgram::set()
{
    glUseProgram(m_id);
}
