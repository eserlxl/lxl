#ifndef lxl_MATH_BINOM_H
#define lxl_MATH_BINOM_H

#include <iostream>
#include <cmath>
#include <vector>
#include "utils/type.h"

/*
                                                                1
                                                        1               1
                                                1               2               1
                                        1               3               3               1
                                1               4               6               4               1
                        1               5               10              10              5               1
                1               6               15              20              15              6               1
        1               7               21              35              35              21              7               1

 */
namespace lxl {
    template<typename T>
    void binom(uzi size, std::vector<std::vector<T>> &hayyam) {
        hayyam.resize(0, std::vector<T>(0));
        hayyam.resize(size * 2, std::vector<T>(size * 2));

        hayyam[0][0] = 1;
        for (uzi i = 0; i <= size; i++) {
            hayyam[i][0] = 1;
            for (uzi j = 0; j <= i; j++) {
                if (j > 0 && i > 0) {
                    hayyam[i][j] = hayyam[i - 1][j - 1] + hayyam[i - 1][j];
                }
            }
        }
    }

    std::string binomTriangle(uzi size);
}
#endif //lxl_MATH_BINOM_H
