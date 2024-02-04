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
    void binom(uzi index, std::vector<std::vector<T>> &hayyam) {
        hayyam.resize(index+1);

        for (uzi i = 0; i <= index; i++) {
            hayyam[i].resize(i+1);
            hayyam[i][0] = 1;
            for (uzi j = 1; j < i; j++) {
                hayyam[i][j] = hayyam[i-1][j - 1] + hayyam[i-1][j];
            }
            hayyam[i][i] = 1;
        }
    }

    matrixUzi2D binom(uzi index);

    std::string binomTriangle(uzi index);
}
#endif //lxl_MATH_BINOM_H
