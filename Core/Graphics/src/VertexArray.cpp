#include "VertexArray.h"

#include "Graphics_common.h"

VertexArray::VertexArray(int count, GLuint type, GLboolean normalised, GLuint stride, GLvoid* textureOffset):
    m_id(0), m_bufferId(0)

{
    GL_CALL(glGenVertexArrays(1, &m_id));
    GL_CALL(glGenBuffers(1, &m_bufferId));
    GL_CALL(glBindVertexArray(m_id));
    GL_CALL(glVertexAttribPointer(m_id,
        count,
        type,
        normalised,
        stride,
        textureOffset));
}
