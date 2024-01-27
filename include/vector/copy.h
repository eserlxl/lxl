#ifndef lxl_VECTOR_COPY_H_
#define lxl_VECTOR_COPY_H_

#include <vector>

namespace lxl {
    template<typename T1, typename T2>
    void copyVec(std::vector<std::vector<std::vector<T1>>> &source, std::vector<std::vector<std::vector<T2>>> &target) {
        unsigned int maxSize = 0;
        unsigned int maxSize2 = 0;
        for (unsigned int i = 0; i < source.size(); i++) {
            if (maxSize < source[i].size()) {
                maxSize = source[i].size();
            }

            for (unsigned int j = 0; j < source[i].size(); j++) {
                if (maxSize2 < source[i][j].size()) {
                    maxSize2 = source[i][j].size();
                }
            }
        }

        target.resize(source.size(), std::vector<std::vector<T2> >(maxSize, std::vector<T2>(maxSize2)));

        for (unsigned int i = 0; i < source.size(); i++) {
            for (unsigned int j = 0; j < source[i].size(); j++) {
                for (unsigned int k = 0; k < source[i][j].size(); k++) {
                    target[i][j][k] = source[i][j][k];
                }
                target[i][j].resize(source[i][j].size());
            }
        }
    }

    template<typename T1, typename T2>
    void copyVec(std::vector<std::vector<T1>> &source, std::vector<std::vector<T2>> &target) {
        unsigned int maxSize = 0;
        for (unsigned int i = 0; i < source.size(); i++) {
            if (maxSize < source[i].size()) {
                maxSize = source[i].size();
            }
        }

        target.resize(source.size(), std::vector<T2>(maxSize));

        for (unsigned int i = 0; i < source.size(); i++) {
            for (unsigned int j = 0; j < source[i].size(); j++) {
                target[i][j] = source[i][j];
            }
            target[i].resize(source[i].size());
        }
    }

    template<typename T1, typename T2>
    void copyVec(std::vector<T1> &source, std::vector<T2> &target) {
        target.resize(source.size());

        for (unsigned int i = 0; i < source.size(); i++) {
            target[i] = source[i];
        }
    }

    template<class A, class B>
    void copy(A &source, B &target) {
        target.clear();
        if (!source.empty()) {
            copyVec(source, target);
        }
    }

    template<typename T1, typename T2>
    void convert(const std::vector<T1> &source, std::vector<T2> &target) {
        target.reserve(source.size());
        for (auto &j : source) {
            target.push_back(convert<T2>(j));
        }
    }
}
#endif // lxl_VECTOR_COPY_H_
