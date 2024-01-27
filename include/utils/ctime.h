#ifndef lxl_UTILS_TIME_H_
#define lxl_UTILS_TIME_H_

#include <chrono>

namespace lxl {
    typedef std::chrono::steady_clock::time_point timer;

    void initTimer(timer *T);

    double elapsedTime(timer T);
}
#endif // lxl_UTILS_TIME_H_
