#include "VertexArray.h"

VertexArray::VertexArray(int count, GLuint type, GLboolean normalised, GLuint stride, GLvoid* textureOffset):
	m_id(0)

{
	glBindVertexArray(m_id);
	glVertexAttribPointer(m_id,
		count,
		type,
		normalised,
		stride,
		textureOffset);
}
