#ifndef lxl_MATH_COMBINATION_H_
#define lxl_MATH_COMBINATION_H_

#include <iostream>
#include <vector>
#include "utils.h"

namespace lxl {
    template<typename T>
    void combination(const std::vector<T> &s, std::vector<T> &pos, uzi n, std::vector<std::vector<T>> &y) {
        if (n == pos.size()) {
            std::vector<T> tempVec;
            for (uzi i = 0; i != n; i++) {
                //std::cout << s[pos[i]];
                tempVec.push_back(s[pos[i]]);
            }
            y.push_back(tempVec);
            //std::cout << std::endl;
            return;
        }
        for (uzi i = 0; i != s.size(); i++) {
            pos[n] = i;
            combination(s, pos, n + 1, y);
        }
    }

    template<typename T>
    void combine(std::vector<T> a, std::vector<std::vector<T>> &y) {
        std::vector<uzi> p;
        for (uzi i = 0; i < a.size(); i++) {
            p.push_back(1);
            combination(a, p, 0, y);
        }
    }
}
#endif /* lxl_MATH_COMBINATION_H_ */
