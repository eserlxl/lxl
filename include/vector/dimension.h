#ifndef lxl_VECTOR_DIMENSION_H_
#define lxl_VECTOR_DIMENSION_H_

#include <vector>
#include "type.h"

namespace lxl {
// Supports up to 5 dimension for now!

    template<typename T>
    uzi dimension(std::vector<T> &a) {
        return 1;
    }

    template<typename T>
    uzi dimension(std::vector<std::vector<T>> &a) {
        return 2;
    }

    template<typename T>
    uzi dimension(std::vector<std::vector<std::vector<T>>> &a) {
        return 3;
    }

    template<typename T>
    uzi dimension(std::vector<std::vector<std::vector<std::vector<T>>>> &a) {
        return 4;
    }

    template<typename T>
    uzi dimension(std::vector<std::vector<std::vector<std::vector<std::vector<T>>>>> &a) {
        return 5;
    }

    template<class A>
    uzi dimension(A v) {
        return dimension(v);
    }
}
#endif //lxl_VECTOR_DIMENSION_H_
