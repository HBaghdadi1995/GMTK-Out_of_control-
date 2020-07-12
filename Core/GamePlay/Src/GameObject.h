//Copywright (C) 2020 Hasan Al-Baghdadi
#pragma once
#include "GraphicalObject.h"

struct Position {
	float x = 0;
	float y = 0;
};

class GameObject
{
public:
	GameObject();
	~GameObject();

	void Move(float x, float y);
	void SetPosition(float x, float y);

	void setGraphicalObject(GraphicalObject*  graphics);

protected:
	GraphicalObject* m_Graphics = nullptr;
	Position m_Position;
};