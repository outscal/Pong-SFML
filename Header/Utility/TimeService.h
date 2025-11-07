
#pragma once
#include <chrono>

namespace Utility
{
    class TimeService
    {
    private:
        std::chrono::steady_clock::time_point previous_time;
        float delta_time;
    }
}