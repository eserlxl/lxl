#ifndef lxl_ALGO_DISTINCT_H
#define lxl_ALGO_DISTINCT_H

#include "algo/sort.h"
#include "vector/copy.h"

namespace lxl {
    template<typename T>
    uzi countDistinct(const T arr[], uzi n) {
        // First sort the array so that all
        // occurrences become consecutive
        sort(arr, arr + n);

        // Traverse the sorted array
        uzi res = 0;
        for (uzi i = 0; i < n; i++) {

            // Move the index ahead while
            // there are duplicates
            while (i < n - 1 && arr[i] == arr[i + 1]) {
                i++;
            }

            res++;
        }

        return res;
    }

    template<typename T>
    uzi distinctSort(std::vector<T> sourceArray, std::vector<T> &distinctSortedArray) {
        uzi n = sourceArray.size();
        std::vector<T> sortedArray;
        copy(sourceArray, sortedArray);

        // First sort the array so that all
        // occurrences become consecutive
        sort(sortedArray);

        // Traverse the sorted array
        uzi res = 0;
        for (uzi i = 0; i < n; i++) {

            distinctSortedArray.push_back(sortedArray[i]);

            // Move the index ahead while
            // there are duplicates
            while (i < n - 1 && sortedArray[i] == sortedArray[i + 1]) {
                i++;
            }

            res++;
        }

        return res;
    }
}
#endif //lxl_ALGO_DISTINCT_H
