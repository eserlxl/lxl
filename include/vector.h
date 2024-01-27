#ifndef lxl_VECTOR_H_
#define lxl_VECTOR_H_

#include "utils/type.h"
#include "vector/create.h"
#include "vector/copy.h"
#include "vector/cmath.h"
#include "vector/size.h"
#include "vector/dimension.h"
#include "vector/print.h"
#include "vector/statistics.h"

namespace lxl {
    template<class A>
    void zero(A &v) {
        uzi size = v.size();
        v.resize(0);
        v.resize(size, 0);
    }

    template<class A>
    void zero(A &v, uint size) {
        v.resize(0);
        v.resize(size, 0);
    }

    template<typename T>
    void zero(std::vector<T> &v) {
        uzi size = v.size();
        v.resize(0);
        v.resize(size, 0);
    }

    template<typename T>
    void zero(std::vector<std::vector<T>> &v) {
        for (uzi i = 0; i < v.size(); i++) {
            uzi size = v[i].size();
            v[i].resize(0);
            v[i].resize(size, 0);
        }
    }

    template<class A>
    void fill(A &v, A x) {
        uzi size = v.size();
        v.resize(0);
        v.resize(size, x);
    }

    template<typename T>
    void fill(std::vector<T> &v, T x) {
        uzi size = v.size();
        v.resize(0);
        v.resize(size, x);
    }

    template<typename T>
    void fill(std::vector<std::vector<T>> &v, T x) {
        for (uzi i = 0; i < v.size(); i++) {
            uzi size = v[i].size();
            v[i].resize(0);
            v[i].resize(size, x);
        }
    }

    template<class A, typename T>
    void add(A &v, uzi size, T x) {
        v.resize(size + v.size(), x);
    }

    template<typename T>
    void resize(std::vector<std::vector<T>> &v, uzi sizeRow, uzi sizeCol) {
        v.resize(0);
        v.resize(sizeRow);
        for (uzi i = 0; i < sizeRow; i++) {
            v[i].resize(0);
            v[i].resize(sizeCol, 0);
        }
    }
}

#endif // lxl_VECTOR_H_
