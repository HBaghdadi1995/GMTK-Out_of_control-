#include "Shader.h"

Shader::Shader(std::string vertex, std::string fragment)
{
    LoadShaders(vertex, fragment);
}

Shader::~Shader()
{
    glDeleteShader(m_Program);
}

void Shader::Bind()
{
	glUseProgram(m_Program);
}

void Shader::Unbind()
{
	glUseProgram(0);
}

Shader* Shader::GenerateBasicShaders()
{
    return new Shader(
        std::string(SHADER_SRC) + std::string("basic.vert"),
        std::string(SHADER_SRC) + std::string("basic.frag"));
}

void Shader::LoadShaders(std::string vertex, std::string fragment)
{

    m_Program = glCreateProgram();

    compileShader(vertex, GL_VERTEX_SHADER);
    compileShader(fragment, GL_FRAGMENT_SHADER);

    glLinkProgram(m_Program);
}

void Shader::compileShader(std::string address, GLuint type)
{
    const char* src = LoadFile(address).c_str();

    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL); // vertex_shader_source is a GLchar* containing glsl shader source code
    glCompileShader(shader);

    GLint vertex_compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &vertex_compiled);
    if (vertex_compiled != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(shader, 1024, &log_length, message);
        std::cout << message;
        assert(false);
    }

    glAttachShader(m_Program, shader);
    glDeleteShader(shader);
}

std::string Shader::LoadFile(std::string address)
{
    std::ifstream file;
    file.open(address);

    std::string data = "";

    char c = file.get();

    while (file.good()) {
        data += c;
        c = file.get();
    }

    return data;
}
