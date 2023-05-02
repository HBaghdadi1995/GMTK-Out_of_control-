#pragma once
#include "glad/glad.h"
class VertexArray
{
private:
    GLuint m_id;
    GLuint m_bufferId;
public:
    VertexArray(int count, GLuint type, GLboolean normalised, GLuint stride, GLvoid* textureOffset);
    ~VertexArray();
};

