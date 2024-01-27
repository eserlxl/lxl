#ifndef lxl_ALGO_SORT_SELECTIONSORT_H_
#define lxl_ALGO_SORT_SELECTIONSORT_H_

#include <vector>
#include "algo/swap.h"

namespace lxl {
    template<typename T>
    void selectionSort(T arr[], int n) {
        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the required element in unsorted array
            int reqI = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[reqI]) {
                    reqI = j;
                }
            }

            // Swap the found minimum element with the first element
            swap(&arr[reqI], &arr[i]);
        }
    }

    template<typename T>
    void selectionSort(std::vector<T> &arr) {
        int n = arr.size();

        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the required element in unsorted array
            int reqI = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[reqI]) {
                    reqI = j;
                }
            }

            // Swap the found minimum element with the first element
            swap(&arr[reqI], &arr[i]);
        }
    }

    template<typename T>
    void selectionRSort(T arr[], int n) {
        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the required element in unsorted array
            int reqI = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[reqI]) {
                    reqI = j;
                }
            }

            // Swap the found minimum element with the first element
            swap(&arr[reqI], &arr[i]);
        }
    }

    template<typename T>
    void selectionRSort(std::vector<T> &arr) {
        int n = arr.size();

        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n - 1; i++) {
            // Find the required element in unsorted array
            int reqI = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[reqI]) {
                    reqI = j;
                }
            }

            // Swap the found minimum element with the first element
            swap(&arr[reqI], &arr[i]);
        }
    }
}
#endif // lxl_ALGO_SORT_SELECTIONSORT_H_
