#ifndef lxl_ALGO_COMPARE_H_
#define lxl_ALGO_COMPARE_H_

#include <cmath>
#include <limits>
#include <iomanip>
#include <iostream>
#include <type_traits>
#include <algorithm>
#include "algo/size.h"

namespace lxl {
// https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon
    template<class T>
    typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
    almostEqual(T x, T y, int ulp) {
        // the machine epsilon has to be scaled to the magnitude of the values used
        // and multiplied by the desired precision in ULPs (units in the last place)
        return std::fabs(x - y) <= std::numeric_limits<T>::epsilon() * std::fabs(x + y) * ulp
               // unless the result is subnormal
               || std::fabs(x - y) < std::numeric_limits<T>::min();
    }

    template<class type1, class type2>
    bool isSame(type1 a, type2 b) {
        unsigned int s = size(a);
        if (s != size(b)) {
            return false;
        }

        for (unsigned int i = 0; i < s; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    template<class type1, class type2>
    bool equal(type1 a, type2 b) {
        return isSame(a, b);
    }

    template<class type1, class type2>
    bool isEqual(type1 a, type2 b) {
        return isSame(a, b);
    }
}
#endif // lxl_ALGO_COMPARE_H_
