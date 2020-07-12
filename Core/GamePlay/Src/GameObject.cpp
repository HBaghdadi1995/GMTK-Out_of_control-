#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{
}

void GameObject::Move(float x, float y)
{
	SetPosition(m_Position.x + x, m_Position.y + y);
}

void GameObject::SetPosition(float x, float y)
{
	m_Position = { x,y };
	m_Graphics->setCoords(x, y);
}

void GameObject::setGraphicalObject(GraphicalObject* graphics)
{
	m_Graphics = graphics;
}
