#include "VertexArray.h"

VertexArray::VertexArray(int count, GLuint type, GLboolean normalised, GLuint stride, GLvoid* textureOffset):
	m_id(0)

{
	glGenVertexArrays(1, &m_id);
	glBindVertexArray(m_id);
	glVertexAttribPointer(m_id,
		count,
		type,
		normalised,
		stride,
		textureOffset);
}
