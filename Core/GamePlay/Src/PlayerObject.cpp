#include "PlayerObject.h"

void PlayerObject::BindControlls()
{
	InputManager::Instance()->OnKeyHold(FORWARD, std::bind(&PlayerObject::MoveUp, this));
	InputManager::Instance()->OnKeyHold(BACK, std::bind(&PlayerObject::MoveDown, this));
	InputManager::Instance()->OnKeyHold(LEFT, std::bind(&PlayerObject::MoveLeft, this));
	InputManager::Instance()->OnKeyHold(RIGHT, std::bind(&PlayerObject::MoveRight, this));
}

void PlayerObject::MoveUp()
{
	Move(0.0f, -speed);
}

void PlayerObject::MoveDown()
{
	Move(0.0f, speed);
}

void PlayerObject::MoveLeft()
{
	Move(-speed, 0.0f);
}

void PlayerObject::MoveRight()
{
	Move(speed, 0.0f);
}
