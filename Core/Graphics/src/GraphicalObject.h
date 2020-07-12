#pragma once
#include "Texture.h"
#include "Shape.h"
#include "Shader.h"

struct AssociatedTexture
{
	Texture* texture = nullptr;
	float xBegin = 0.0f;
	float xEnd = 1.0f;
	float yBegin = 0.0f;
	float yEnd = 1.0f;
};

class GraphicalObject
{
public:
	GraphicalObject(float xCoord, float yCoord, Shader *shader, AssociatedTexture associatedTexture);
	~GraphicalObject();

	void Draw();

	void setCoords(float x, float y);

private:
	AssociatedTexture m_AssociatedTexture;
	Shape* m_AssociatedShape = nullptr;
	Shader* m_AssociatedShader = nullptr;

	float m_XCoord = 0.0f;
	float m_YCoord = 0.0f;
};