#pragma once
#include <iostream>
#include <chrono>
// #include "Singleton.h" //todo: have a base singleton template class

class FrameTime
{
public:
    static FrameTime *getInstance()
    {
        if(!instance)
        {
            instance = new FrameTime();
            instance->currentTime = instance->time_since_epoch();
            instance->lastTime =  instance->time_since_epoch();
            instance->lastTolastTime = instance->time_since_epoch();
        }
        return instance;
    }

    int64_t currentTime;

    int64_t time_since_epoch()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>
            (std::chrono::system_clock::now().time_since_epoch()).count();
    }

    void UpdateFrameTime()
    {
        instance->lastTolastTime = instance->lastTime;
        instance->lastTime = instance->currentTime;
    }

    int64_t GetFrameTime()
    {
        instance->currentTime =  instance->time_since_epoch();
        return instance->currentTime-instance->lastTime;
    }

    float deltaTime()
    {
        return ((float)(instance->lastTime - instance->lastTolastTime))/1000000;
    }
private:
    int64_t lastTime;
    int64_t lastTolastTime;
    static FrameTime* instance;
};

FrameTime* FrameTime::instance = nullptr;