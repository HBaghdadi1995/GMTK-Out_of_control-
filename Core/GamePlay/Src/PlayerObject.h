//Copywright (C) 2020 Hasan Al-Baghdadi
#pragma once
#include "GameObject.h"
#include "InputManager.h"

class PlayerObject: public GameObject
{
public:
	virtual void BindControlls();

protected:
	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();

	float speed = 0.1f;
};

