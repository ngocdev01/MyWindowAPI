//
// Created by ericg on 11/8/2024.
//

#include "../include/mwindow/mTime.h"

mTime::time_point mTime::now()
{
    return std::chrono::system_clock::now();
}

std::chrono::seconds mTime::delta()
{
    return std::chrono::duration_cast<std::chrono::seconds>(deltaTime);
}

void mTime::tick()
{
    previous = current;
    current = now();
    deltaTime = (current - previous);
}

mTime::mTime()
{
    const auto now = std::chrono::system_clock::now();
    start = now;
    stop = now;
    current = now;
    previous = now;
}
