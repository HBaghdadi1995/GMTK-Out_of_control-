#include "GraphicalObject.h"

GraphicalObject::GraphicalObject(float xCoord, float yCoord, Shader* shader, AssociatedTexture associatedTexture):
    m_XCoord(xCoord), m_YCoord(yCoord), m_AssociatedShader(shader), m_AssociatedTexture(associatedTexture)

{
    m_AssociatedShape = Shape::GenerateTile(m_XCoord, m_YCoord, m_AssociatedTexture.xBegin, m_AssociatedTexture.xEnd, m_AssociatedTexture.yBegin, m_AssociatedTexture.yEnd);
    
}

GraphicalObject::~GraphicalObject()
{
    delete m_AssociatedShape;
}

void GraphicalObject::Draw()
{
    m_AssociatedTexture.texture->Bind();

    m_AssociatedShader->Bind();
    m_AssociatedShader->setUniform("u_Texture", m_AssociatedTexture.texture->getSlot());
    
    m_AssociatedShape->Bind();
    m_AssociatedShape->Draw();
}

void GraphicalObject::setCoords(float x, float y)
{
    m_XCoord = x;
    m_YCoord = y;
    
    m_AssociatedShape->setTileCoords(x,y);
}

void GraphicalObject::moveCoords(float x, float y)
{
    setCoords(m_XCoord + x, m_YCoord + y);
}
