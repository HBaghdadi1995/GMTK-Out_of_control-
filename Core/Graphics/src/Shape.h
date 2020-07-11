#pragma once
#include <glad/glad.h>

struct Vertex2d {
	float x;
	float y;

	const static inline unsigned int count() { return 2; }
};

class Shape
{
private:
	Vertex2d* m_Verticies;
	GLuint m_VertexBuffer;
	unsigned int m_Count;
public:
	Shape(Vertex2d* verticies, unsigned int count);
	~Shape();

	void Draw();

	void Bind();
	void Unbind();

	static Shape* GenerateSquare();
	static Shape* GenerateTile(float x, float y);
};

