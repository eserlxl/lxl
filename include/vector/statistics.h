#ifndef lxl_STATISTICS_H
#define lxl_STATISTICS_H

#include <iostream>
#include <vector>
#include "utils.h"

namespace lxl {
    template<typename T, uzi windowSize>
    class movingStat {
    public:

        movingStat() {
            data.resize(windowSize);
        }

        T mean(T x) {
            sum += x;

            if (dataCount >= windowSize) {
                sum -= data[dataCount % windowSize];
            }

            data[dataCount++ % windowSize] = x;

            return sum / std::min(dataCount, windowSize);
        }

        T moment(T x, long double power) {
            return this->mean(powl(x, power));
        }

    private:
        std::vector<T> data;
        uzi dataCount{0};
        T sum{0};
    };
}
#endif //lxl_STATISTICS_H
