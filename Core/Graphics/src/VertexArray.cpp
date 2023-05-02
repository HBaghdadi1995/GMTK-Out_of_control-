#include "VertexArray.h"

VertexArray::VertexArray(int count, GLuint type, GLboolean normalised, GLuint stride, GLvoid* textureOffset):
    m_id(0), m_bufferId(0)

{
    glGenVertexArrays(1, &m_id);
    glGenBuffers(1, &m_bufferId);
    glBindVertexArray(m_id);
    glVertexAttribPointer(m_id,
        count,
        type,
        normalised,
        stride,
        textureOffset);
}
