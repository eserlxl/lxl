#ifndef lxl_ALGO_SORT_H_
#define lxl_ALGO_SORT_H_

#include "algo/sort/mergeSort.h"
#include "algo/sort/selectionSort.h"
#include "algo/sort/insertionSort.h"
#include "algo/sort/timSort.h"

namespace lxl {
    template<typename T>
    void sort(T arr[], uzi n) {
        timSort(arr, n);
    }

    template<typename T>
    void sort(std::vector<T> &arr) {
        timSort(arr);
    }

    template<typename T>
    void rSort(T arr[], uzi n) {
        timRSort(arr, n);
    }

    template<typename T>
    void rSort(std::vector<T> &arr) {
        timRSort(arr);
    }
}
#endif // lxl_ALGO_SORT_H_
