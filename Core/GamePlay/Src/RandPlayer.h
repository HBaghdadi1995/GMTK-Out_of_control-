//Copywright (C) 2020 Hasan Al-Baghdadi
#pragma once
#include "PlayerObject.h"
#include "InputManager.h"
#include <time.h>
#include <algorithm>

#define RAND_VERTICAL 0x01
#define RAND_POSITIVE 0x02

class RandPlayerObject : public PlayerObject
{
public:
	virtual void BindControlls();

	bool ShouldLose();

	unsigned long long int score = 0;
	float speed = 0.01f;

protected:
	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();

	void RandomUp();
	void RandomDown();
	void RandomLeft();
	void RandomRight();

	void RandomMove(unsigned int val);

	unsigned int m_UpVal = 0x01;
	unsigned int m_DownVal = 0x03;
	unsigned int m_LeftVal = 0x00;
	unsigned int m_RightVal = 0x02;

};
