#pragma once

#include <assert.h>
#include <fstream>
#include <iostream>
#include <unordered_map>

#include <string>
#include <sstream>

#include <glad/glad.h>

#include "Graphics_Common.h"

#ifdef DIST

#define SHADER_SRC "./Src/Shaders/"

#else //DIST

#define SHADER_SRC "../../Src/Shaders/"

#endif //DIST

class Shader
{
private:
    GLint m_Program;
    std::unordered_map<std::string, GLint> uniformLocationCache;
public:
    Shader(std::string vertex, std::string fragment);
    ~Shader();

    void Bind();
    void Unbind();

    static Shader* GenerateBasicShaders();
    static Shader* GenerateTileShaders();
    static Shader* GenerateTexturedTileShaders();


private:
    void LoadShaders(std::string vertAddress, std::string fragAddress);
    void compileShader(std::string address, GLuint type);
    static void LoadFile(std::string address, std::string &data);
    GLint getUniformLocation(std::string uniformName);
public:

    template <typename T>
    void setUniform(std::string uniformName, T value) {
        assert(false);
    }

    template<>
    void setUniform(std::string uniformName, int value) {
        GL_CALL(glUniform1i(getUniformLocation(uniformName), value));
    }
};