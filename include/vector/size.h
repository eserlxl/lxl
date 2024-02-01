#ifndef lxl_VECTOR_SIZE_H_
#define lxl_VECTOR_SIZE_H_

#include <vector>
#include "utils/type.h"

namespace lxl {
// Supports up to 5 dimension for now!

    template<typename T>
    matrixUzi1D sizeVec(std::vector<T> &v) {
        matrixUzi1D sizeVec;

        sizeVec.push_back(v.size());

        return sizeVec;
    }

    template<typename T>
    matrixUzi1D sizeVec(std::vector<std::vector<T>> &v) {
        matrixUzi1D sizeVec;

        sizeVec.push_back(v.size());
        sizeVec.push_back(v[0].size());

        return sizeVec;
    }

    template<typename T>
    matrixUzi1D sizeVec(std::vector<std::vector<std::vector<T>>> &v) {
        matrixUzi1D sizeVec;

        sizeVec.push_back(v.size());
        sizeVec.push_back(v[0].size());
        sizeVec.push_back(v[0][0].size());

        return sizeVec;
    }

    template<typename T>
    matrixUzi1D sizeVec(std::vector<std::vector<std::vector<std::vector<T>>>> &v) {
        matrixUzi1D sizeVec;

        sizeVec.push_back(v.size());
        sizeVec.push_back(v[0].size());
        sizeVec.push_back(v[0][0].size());
        sizeVec.push_back(v[0][0][0].size());

        return sizeVec;
    }

    template<typename T>
    matrixUzi1D sizeVec(std::vector<std::vector<std::vector<std::vector<std::vector<T>>>>> &v) {
        matrixUzi1D sizeVec;

        sizeVec.push_back(v.size());
        sizeVec.push_back(v[0].size());
        sizeVec.push_back(v[0][0].size());
        sizeVec.push_back(v[0][0][0].size());
        sizeVec.push_back(v[0][0][0][0].size());

        return sizeVec;
    }

    template<class A>
    matrixUzi1D sizeVec(const A &v) {
        return sizeVec(v);
    }
}
#endif //lxl_VECTOR_SIZE_H_
