#ifndef lxl_MATH_PERMUTATION_H_
#define lxl_MATH_PERMUTATION_H_

#include <iostream>
#include <vector>
#include "utils.h"

namespace lxl {
    inline uzi factorial(uzi x) {
        return (x == 1 ? x : x * factorial(x - 1));
    }

    int show(std::vector<uzi> x, uzi len);

    void perm1(std::vector<uzi> x, uzi n, int callback(std::vector<uzi>, uzi));

    void perm2(std::vector<uzi> x, uzi n, int callback(std::vector<uzi>, uzi));

    void perm3(std::vector<uzi> x, uzi n, int callback(std::vector<uzi>, uzi));

    void perm(std::vector<uzi> x, uzi n, std::vector<std::vector<uzi>> &y);
}

#endif /* lxl_MATH_PERMUTATION_H_ */
