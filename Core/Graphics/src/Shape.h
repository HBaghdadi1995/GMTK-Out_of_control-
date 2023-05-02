#pragma once
#include <glad/glad.h>

struct Vertex2d {
    float x;
    float y;
    float texX;
    float texY;

    const static inline unsigned int LocationCount() { return 2; }
    const static inline unsigned int TextureCount() { return 2; }
    const static inline GLvoid* LocationOffset() { return (GLvoid*)0; }
    const static inline GLvoid* TextureOffset() { return (GLvoid*)(2* sizeof(float)); }
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
    static Shape* GenerateTile(float x, float y, float xBegin, float xEnd, float yBegin, float yEnd);

    void setTileCoords(float x, float y);
};

