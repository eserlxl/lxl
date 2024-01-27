#include <chrono>

namespace lxl {
    typedef std::chrono::steady_clock::time_point timer;

    void initTimer(timer *T) {
        *T = std::chrono::steady_clock::now();
    }

    double elapsedTime(timer T) {
        timer N = std::chrono::steady_clock::now();
        return (std::chrono::duration_cast<std::chrono::nanoseconds>(N - T).count()) / 1.e9;
    }
}