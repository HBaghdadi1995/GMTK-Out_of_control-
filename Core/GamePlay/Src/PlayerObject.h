#pragma once
#include "GameObject.h"
#include "InputManager.h"

class PlayerObject: public GameObject
{
public:
	void BindControlls();

protected:
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	float speed = 0.1f;
};

