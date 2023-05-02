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
        0,                          // layout.
        Vertex2d::LocationCount(),  // count
        GL_FLOAT,                   // type
        GL_FALSE,                   // normalized?
        sizeof(Vertex2d),           // stride
        Vertex2d::LocationOffset()  // array buffer offset
    );

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
        1,                          // layout
        Vertex2d::TextureCount(),   // count
        GL_FLOAT,                   // type
        GL_FALSE,                   // normalized?
        sizeof(Vertex2d),           // stride
        Vertex2d::TextureOffset()   // array buffer offset
    );
}

Shape::~Shape()
{
    delete[] m_Verticies;
    glDeleteBuffers(1,&m_VertexBuffer);
}

void Shape::Draw()
{
    Bind();

    glDrawArrays(GL_TRIANGLES, 0, m_Count);
}

void Shape::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
    glVertexAttribPointer(
        0,                          // layout.
        Vertex2d::LocationCount(),  // count
        GL_FLOAT,                   // type
        GL_FALSE,                   // normalized?
        sizeof(Vertex2d),           // stride
        Vertex2d::LocationOffset()  // array buffer offset
    );

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
        1,                          // layout
        Vertex2d::TextureCount(),   // count
        GL_FLOAT,                   // type
        GL_FALSE,                   // normalized?
        sizeof(Vertex2d),           // stride
        Vertex2d::TextureOffset()   // array buffer offset
    );
}

void Shape::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Shape* Shape::GenerateSquare()
{
    unsigned int count = 6;
    Vertex2d* verticies = new Vertex2d[6];
    verticies[0] = {-0.5f,  0.5f, 0.0f, 0.0f};
    verticies[1] = {-0.5f, -0.5f, 0.0f, 1.0f};
    verticies[2] = { 0.5f, -0.5f, 1.0f, 1.0f};
    verticies[3] = { 0.5f,  0.5f, 1.0f, 0.0f};
    verticies[4] = {-0.5f,  0.5f, 0.0f, 0.0f};
    verticies[5] = { 0.5f, -0.5f, 1.0f, 1.0f};


    return new Shape(verticies, count);
}

Shape* Shape::GenerateTile(float x, float y)
{
    unsigned int count = 6;
    Vertex2d* verticies = new Vertex2d[6];
    verticies[0] = { x * 32.0f          ,  y * 32.0f + 32.0f , 0.0f, 0.0f};
    verticies[1] = { x * 32.0f          ,  y * 32.0f         , 0.0f, 1.0f};
    verticies[2] = { x * 32.0f + 32.0f  ,  y * 32.0f         , 1.0f, 1.0f};
    verticies[3] = { x * 32.0f + 32.0f  ,  y * 32.0f + 32.0f , 1.0f, 0.0f};
    verticies[4] = { x * 32.0f          ,  y * 32.0f + 32.0f , 0.0f, 0.0f};
    verticies[5] = { x * 32.0f + 32.0f  ,  y * 32.0f         , 1.0f, 1.0f};


    return new Shape(verticies, count);
}

Shape* Shape::GenerateTile(float x, float y, float xBegin, float xEnd, float yBegin, float yEnd)
{
    unsigned int count = 6;
    Vertex2d* verticies = new Vertex2d[6];
    verticies[0] = { x * 32.0f          ,  y * 32.0f + 32.0f , xBegin , yBegin };
    verticies[1] = { x * 32.0f          ,  y * 32.0f         , xBegin , yEnd   };
    verticies[2] = { x * 32.0f + 32.0f  ,  y * 32.0f         , xEnd   , yEnd   };
    verticies[3] = { x * 32.0f + 32.0f  ,  y * 32.0f + 32.0f , xEnd   , yBegin };
    verticies[4] = { x * 32.0f          ,  y * 32.0f + 32.0f , xBegin , yBegin };
    verticies[5] = { x * 32.0f + 32.0f  ,  y * 32.0f         , xEnd   , yEnd   };


    return new Shape(verticies, count);
}

#include <iostream>

void Shape::setTileCoords(float x, float y)
{
    m_Verticies[0].x = x * 32.0f        ; 
    m_Verticies[1].x = x * 32.0f        ; 
    m_Verticies[2].x = x * 32.0f + 32.0f; 
    m_Verticies[3].x = x * 32.0f + 32.0f; 
    m_Verticies[4].x = x * 32.0f        ; 
    m_Verticies[5].x = x * 32.0f + 32.0f; 

    m_Verticies[0].y = y * 32.0f + 32.0f ;
    m_Verticies[1].y = y * 32.0f         ;
    m_Verticies[2].y = y * 32.0f         ;
    m_Verticies[3].y = y * 32.0f + 32.0f ;
    m_Verticies[4].y = y * 32.0f + 32.0f ;
    m_Verticies[5].y = y * 32.0f         ;

    Bind();
    glBufferData(GL_ARRAY_BUFFER, m_Count * sizeof(Vertex2d), m_Verticies, GL_STATIC_DRAW);
}