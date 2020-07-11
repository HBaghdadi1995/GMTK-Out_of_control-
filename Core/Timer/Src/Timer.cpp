#include "Timer.h"

Timer::Timer(int waitTime_ms):
	m_WaitTime(waitTime_ms)
{
	Timer* t = nullptr;
	if (t) {
		if (t->check()) {
			func();
			delete t;
			t = nullptr;
		}
	}
}

Timer::~Timer()
{
}

void Timer::init()
{
	m_Init = CURRENT_TIME;
}

bool Timer::check()
{
	if (!m_Init) {
		init();
	}
	if (m_Init + m_WaitTime > CURRENT_TIME) {
		return true;
	}
	else
	{
		return false;
	}
}

void Timer::Wait(Timer* t, std::function<void(void)> func)
{
	if (t) {
		if (t->check()) {
			func();
			delete t;
			t = nullptr;
		}
	}
}

void Timer::WaitRepeat(Timer* t, std::function<void(void)> func, int waitTime)
{
	if (t) {
		if (t->check()) {
			func();
			delete t;
			t = nullptr;
		}
	}
	else {
		t = new Timer(waitTime);
		t->init();
	}
}
