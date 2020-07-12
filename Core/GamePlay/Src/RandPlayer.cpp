#include "RandPlayer.h"

void RandPlayerObject::BindControlls()
{
	srand(time(NULL));

	InputManager::Instance()->OnKeyPress(FORWARD, std::bind(&RandPlayerObject::RandomUp, this));
	InputManager::Instance()->OnKeyPress(BACK, std::bind(&RandPlayerObject::RandomDown, this));
	InputManager::Instance()->OnKeyPress(LEFT, std::bind(&RandPlayerObject::RandomLeft, this));
	InputManager::Instance()->OnKeyPress(RIGHT, std::bind(&RandPlayerObject::RandomRight, this));

	InputManager::Instance()->OnKeyHold(FORWARD, std::bind(&RandPlayerObject::MoveUp, this));
	InputManager::Instance()->OnKeyHold(BACK, std::bind(&RandPlayerObject::MoveDown, this));
	InputManager::Instance()->OnKeyHold(LEFT, std::bind(&RandPlayerObject::MoveLeft, this));
	InputManager::Instance()->OnKeyHold(RIGHT, std::bind(&RandPlayerObject::MoveRight, this));
}

bool RandPlayerObject::ShouldLose()
{
	return m_Position.x < 0.5f || m_Position.y < 0.5f || m_Position.x > 18.5f || m_Position.y > 12.5f;
}

void RandPlayerObject::MoveUp()
{
	RandomMove(m_UpVal);
}

void RandPlayerObject::MoveDown()
{
	RandomMove(m_DownVal);
}

void RandPlayerObject::MoveLeft()
{
	RandomMove(m_LeftVal);
}

void RandPlayerObject::MoveRight()
{
	RandomMove(m_RightVal);
}

void RandPlayerObject::RandomUp() {
	speed += 0.01f;
	m_UpVal = static_cast<unsigned int> (rand()) % 0x04;
}

void RandPlayerObject::RandomDown() {
	speed += 0.01f;
	m_UpVal = static_cast<unsigned int> (rand()) % 0x04;
}

void RandPlayerObject::RandomLeft() {
	speed += 0.01f;
	m_LeftVal = static_cast<unsigned int> (rand()) % 0x04;
}

void RandPlayerObject::RandomRight() {
	speed += 0.01f;
	m_UpVal = static_cast<unsigned int> (rand()) % 0x04;
}

void RandPlayerObject::RandomMove(unsigned int val)
{
	int sign = static_cast<int>(val & RAND_POSITIVE);
	sign = (sign) ? 1 : -1;
	score += speed * 100;

	if (val & RAND_VERTICAL) {
		Move(0.0f, speed * sign);
	}
	else {
		Move(speed * sign, 0.0f);
	}
}
