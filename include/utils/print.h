#ifndef lxl_UTILS_PRINT_H_
#define lxl_UTILS_PRINT_H_

#include <iostream>
#include <vector>
#include "utils/type.h"

namespace lxl {
// 2-D
    template<typename T>
    void printVec(T **arr, uzi size1, uzi size2) {
        for (uzi i = 0; i < size1; i++) {
            for (uzi j = 0; j < size2; j++) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

// 1-D
    template<typename T>
    void printVec(T *arr, uzi size) {
        for (uzi i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    void print(T **arr, uzi size1, uzi size2) {
        printVec(arr, size1, size2);
    }

    template<typename T>
    void print(T *arr, uzi size) {
        printVec(arr, size);
    }
}
#endif // lxl_UTILS_PRINT_H_
