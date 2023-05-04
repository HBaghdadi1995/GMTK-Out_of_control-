#include "Shader.h"

Shader::Shader(std::string vertex, std::string fragment)
{
    LoadShaders(vertex, fragment);
}

Shader::~Shader()
{
    GL_CALL(glDeleteProgram(m_Program));
}

void Shader::Bind()
{
    GL_CALL(glUseProgram(m_Program));
}

void Shader::Unbind()
{
    GL_CALL(glUseProgram(0));
}

Shader* Shader::GenerateBasicShaders()
{
    return new Shader(
        std::string(SHADER_SRC) + std::string("basic.vert"),
        std::string(SHADER_SRC) + std::string("basic.frag"));
}

Shader* Shader::GenerateTileShaders()
{
    return new Shader(
        std::string(SHADER_SRC) + std::string("tiles.vert"),
        std::string(SHADER_SRC) + std::string("basic.frag"));
}

Shader* Shader::GenerateTexturedTileShaders()
{
    return new Shader(
        std::string(SHADER_SRC) + std::string("texturedTile.vert"),
        std::string(SHADER_SRC) + std::string("texturedTile.frag"));
}

void Shader::LoadShaders(std::string vertex, std::string fragment)
{

    m_Program = GL_CALL(glCreateProgram());

    compileShader(vertex, GL_VERTEX_SHADER);
    compileShader(fragment, GL_FRAGMENT_SHADER);

    GL_CALL(glLinkProgram(m_Program));

    GLint program_linked;
    GL_CALL(glGetProgramiv(m_Program, GL_LINK_STATUS, &program_linked));
    if (program_linked != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        GL_CALL(glGetProgramInfoLog(m_Program, 1024, &log_length, message));
        std::cerr << message;
        assert(false);
    }
}

void Shader::compileShader(std::string address, GLuint type)
{
    std::string data = "";
    LoadFile(address, data);
    const char* src = data.c_str();

    GLuint shader = GL_CALL(glCreateShader(type));
    GL_CALL(glShaderSource(shader, 1, &src, NULL)); // vertex_shader_source is a GLchar* containing glsl shader source code
    GL_CALL(glCompileShader(shader));

    GLint shader_compiled;
    GL_CALL(glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_compiled));
    if (shader_compiled != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        GL_CALL(glGetShaderInfoLog(shader, 1024, &log_length, message));
        std::cout << src << "\n";
        std::cout << message;
        assert(false);
    }

    GL_CALL(glAttachShader(m_Program, shader));
    GL_CALL(glDeleteShader(shader));
}

void Shader::LoadFile(std::string address, std::string& data)
{
    std::ifstream file(address);

    if (!file.is_open()) {
        std::cerr << "Error: " << strerror(errno);;
    }

    std::string line = "";

    while (getline(file,line)) {
        data += line;
        data += "\n";
    }

    return;
}

GLint Shader::getUniformLocation(std::string uniformName)
{
    GLint location = 0;
    if (uniformLocationCache.find(uniformName) != uniformLocationCache.end()) {
        location = uniformLocationCache[uniformName];
    }
    else {
        location = GL_CALL(glGetUniformLocation(m_Program,uniformName.c_str()));
        uniformLocationCache.insert({uniformName, location});
    }
    return location;
}
