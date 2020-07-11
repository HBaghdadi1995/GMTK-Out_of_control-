#pragma once

#include <assert.h>
#include <fstream>
#include <iostream>

#include <glad/glad.h>

#ifdef DIST

#define SHADER_SRC "./Src/Shaders/"

#else //DIST

#define SHADER_SRC "../../Src/Shaders/"

#endif //DIST

class Shader
{
private:
    GLint m_Program;
public:
    Shader(std::string vertex, std::string fragment);
    ~Shader();

    void Bind();
    void Unbind();

    static Shader* GenerateBasicShaders();
    static Shader* GenerateTileShaders();

private:
    void LoadShaders(std::string vertAddress, std::string fragAddress);
    void compileShader(std::string address, GLuint type);
    static std::string LoadFile(std::string address);
};