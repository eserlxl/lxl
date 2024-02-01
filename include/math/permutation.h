#ifndef lxl_MATH_PERMUTATION_H_
#define lxl_MATH_PERMUTATION_H_

#include <iostream>
#include <vector>
#include "utils/type.h"

namespace lxl {
    inline uzi factorial(uzi x) {
        return (x == 1 ? x : x * factorial(x - 1));
    }

    int show(matrixUzi1D x, uzi len);

    void perm1(matrixUzi1D x, uzi n, int callback(matrixUzi1D, uzi));

    void perm2(matrixUzi1D x, uzi n, int callback(matrixUzi1D, uzi));

    void perm3(matrixUzi1D x, uzi n, int callback(matrixUzi1D, uzi));

    void perm(matrixUzi1D x, uzi n, matrixUzi2D &y);
}

#endif /* lxl_MATH_PERMUTATION_H_ */
