#include "Clock.h"

Clock::Clock(int interval_ms) {
    this->interval_ms = interval_ms;
    lastCallTime = std::chrono::high_resolution_clock::now();
}

bool Clock::time_passed() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastCallTime);

    if (duration.count() > interval_ms) {
        lastCallTime = currentTime;
        return true;
    }
    return false;
}
