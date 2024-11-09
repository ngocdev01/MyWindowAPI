//
// Created by ericg on 11/8/2024.
//

#ifndef MTIME_H
#define MTIME_H
#include <chrono>
#include <iostream>

class mTime {
public:
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::system_clock::time_point;
    using duration = std::chrono::system_clock::duration;
public:
    static time_point now();
    std::chrono::seconds delta();
    void tick();
    mTime();
private:
    time_point previous;
    time_point current;
    time_point start;
    time_point stop;
    duration deltaTime;
};



#endif //MTIME_H
