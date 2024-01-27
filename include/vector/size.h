#ifndef lxl_VECTOR_SIZE_H_
#define lxl_VECTOR_SIZE_H_

#include <vector>
#include "utils.h"

namespace lxl {
// Supports up to 5 dimension for now!

    template<typename T>
    std::vector<uzi> sizeVec(std::vector<T> &v) {
        std::vector<uzi> sizeVec;

        sizeVec.push_back(v.size());

        return sizeVec;
    }

    template<typename T>
    std::vector<uzi> sizeVec(std::vector<std::vector<T>> &v) {
        std::vector<uzi> sizeVec;

        sizeVec.push_back(v.size());
        sizeVec.push_back(v[0].size());

        return sizeVec;
    }

    template<typename T>
    std::vector<uzi> sizeVec(std::vector<std::vector<std::vector<T>>> &v) {
        std::vector<uzi> sizeVec;

        sizeVec.push_back(v.size());
        sizeVec.push_back(v[0].size());
        sizeVec.push_back(v[0][0].size());

        return sizeVec;
    }

    template<typename T>
    std::vector<uzi> sizeVec(std::vector<std::vector<std::vector<std::vector<T>>>> &v) {
        std::vector<uzi> sizeVec;

        sizeVec.push_back(v.size());
        sizeVec.push_back(v[0].size());
        sizeVec.push_back(v[0][0].size());
        sizeVec.push_back(v[0][0][0].size());

        return sizeVec;
    }

    template<typename T>
    std::vector<uzi> sizeVec(std::vector<std::vector<std::vector<std::vector<std::vector<T>>>>> &v) {
        std::vector<uzi> sizeVec;

        sizeVec.push_back(v.size());
        sizeVec.push_back(v[0].size());
        sizeVec.push_back(v[0][0].size());
        sizeVec.push_back(v[0][0][0].size());
        sizeVec.push_back(v[0][0][0][0].size());

        return sizeVec;
    }

    template<class A>
    std::vector<uzi> sizeVec(const A &v) {
        return sizeVec(v);
    }
}
#endif //lxl_VECTOR_SIZE_H_
