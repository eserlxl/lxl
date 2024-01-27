#ifndef lxl_VECTOR_CREATE_H_
#define lxl_VECTOR_CREATE_H_

#include <string>
#include <vector>
#include "utils/type.h"

namespace lxl {
    template<typename T>
    std::vector<T> createVec(T *a, uzi size) {
        std::vector<T> array;

        for (uzi i = 0; i < size; i++) {
            array.push_back(a[i]);
        }

        return array;
    }

    template<typename T>
    std::vector<std::vector<T>> createVec(T **a, uzi size1, uzi size2) {
        std::vector<std::vector<T>> array;

        for (uzi i = 0; i < size1; i++) {
            array.push_back(createVec(a[i], size2));
        }

        return array;
    }

    template<typename T>
    std::vector<std::vector<std::vector<T>>> createVec(T ***a, uzi size1, uzi size2, uzi size3) {
        std::vector<std::vector<std::vector<T>>> array;

        for (uzi i = 0; i < size1; i++) {
            array.push_back(createVec(a[i], size2, size3));
        }

        return array;
    }
}
#endif // lxl_VECTOR_CREATE_H_
