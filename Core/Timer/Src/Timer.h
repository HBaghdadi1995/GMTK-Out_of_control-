//Copywright (C) 2020 Hasan Al-Baghdadi
#pragma once
#include <chrono>
#include <optional>
#include <functional>
#define CURRENT_TIME std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch()).count()

#define LAMBDA(x) [&](){x}

class Timer
{
public:
    Timer(int waitTime_ms);
    ~Timer();

    void init();
    bool check();

    static void Wait(Timer** t, std::function<void(void)> func);
    static void WaitRepeat(Timer** t, std::function<void(void)> func, int waitTime);

private:
    unsigned long long int m_Init = 0;
    unsigned long long int m_WaitTime = 0;
    
};