#include "Shape.h"

Shape::Shape(Vertex2d* verticies, unsigned int count):
    m_Verticies(verticies),
    m_Count(count)
{
    glGenBuffers(1, &m_VertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, m_Count * sizeof(Vertex2d), m_Verticies, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        Vertex2d::count(),  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        sizeof(Vertex2d),   // stride
        0                   // array buffer offset
    );
}

Shape::~Shape()
{
    delete[] m_Verticies;
    glDeleteBuffers(1,&m_VertexBuffer);
}

void Shape::Draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
    glDrawArrays(GL_TRIANGLES, 0, m_Count);
}

void Shape::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
}

void Shape::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Shape* Shape::GenerateSquare()
{
    unsigned int count = 6;
    Vertex2d* verticies = new Vertex2d[6];
    verticies[0] = {-0.5f,  0.5f};
    verticies[1] = {-0.5f, -0.5f};
    verticies[2] = { 0.5f, -0.5f};
    verticies[3] = { 0.5f,  0.5f};
    verticies[4] = {-0.5f,  0.5f};
    verticies[5] = { 0.5f, -0.5f};


	return new Shape(verticies, count);
}
