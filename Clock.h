#pragma once
#include <chrono>

class Clock {
private:
    int interval_ms;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastCallTime;

public:
    Clock(int interval_ms);
    bool time_passed();
};
