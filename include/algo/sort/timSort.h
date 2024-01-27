#ifndef lxl_ALGO_SORT_TIMSORT_H_
#define lxl_ALGO_SORT_TIMSORT_H_

#include <vector>
#include "algo/sort/selectionSort.h"
#include "algo/sort/mergeSort.h"
#include "utils/type.h"

namespace lxl {
// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
    template<typename T>
    void timSort(T arr[], uzi n) {
        uzi RUN = 32;

        // Sort individual subarrays of size RUN
        for (uzi i = 0; i < n; i += RUN) {
            insertionSort(arr, i, std::min((i + RUN - 1), (n - 1)));
        }

        // start merging from size RUN (or 32). It will merge
        // to form size 64, then 128, 256 and so on ....
        for (uzi size = RUN; size < n; size = 2 * size) {
            // pick starting point of left sub array. We
            // are going to merge arr[left..left+size-1]
            // and arr[left+size, left+2*size-1]
            // After every merge, we increase left by 2*size
            for (uzi left = 0; left < n; left += 2 * size) {
                // find ending point of left sub array
                // mid+1 is starting point of right sub array
                uzi mid = left + size - 1;
                uzi right = std::min((left + 2 * size - 1), (n - 1));

                // merge sub array arr[left.....mid] &
                // arr[mid+1....right]
                mergeSort(arr, left, mid, right);
            }
        }
    }

// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
    template<typename T>
    void timSort(std::vector<T> &arr) {
        uzi RUN = 32;
        uzi n = arr.size();

        // Sort individual subarrays of size RUN
        for (uzi i = 0; i < n; i += RUN) {
            insertionSort(arr, i, std::min((i + RUN - 1), (n - 1)));
        }

        // start merging from size RUN (or 32). It will merge
        // to form size 64, then 128, 256 and so on ....
        for (uzi size = RUN; size < n; size = 2 * size) {
            // pick starting point of left sub array. We
            // are going to merge arr[left..left+size-1]
            // and arr[left+size, left+2*size-1]
            // After every merge, we increase left by 2*size
            for (uzi left = 0; left < n; left += 2 * size) {
                // find ending point of left sub array
                // mid+1 is starting point of right sub array
                uzi mid = left + size - 1;
                uzi right = std::min((left + 2 * size - 1), (n - 1));

                // merge sub array arr[left.....mid] &
                // arr[mid+1....right]
                mergeSort(arr, left, mid, right);
            }
        }
    }

// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
    template<typename T>
    void timRSort(T arr[], uzi n) {
        uzi RUN = 32;

        // Sort individual subarrays of size RUN
        for (uzi i = 0; i < n; i += RUN) {
            insertionRSort(arr, i, std::min((i + RUN - 1), (n - 1)));
        }

        // start merging from size RUN (or 32). It will merge
        // to form size 64, then 128, 256 and so on ....
        for (uzi size = RUN; size < n; size = 2 * size) {
            // pick starting point of left sub array. We
            // are going to merge arr[left..left+size-1]
            // and arr[left+size, left+2*size-1]
            // After every merge, we increase left by 2*size
            for (uzi left = 0; left < n; left += 2 * size) {
                // find ending point of left sub array
                // mid+1 is starting point of right sub array
                uzi mid = left + size - 1;
                uzi right = std::min((left + 2 * size - 1), (n - 1));

                // merge sub array arr[left.....mid] &
                // arr[mid+1....right]
                mergeRSort(arr, left, mid, right);
            }
        }
    }

// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
    template<typename T>
    void timRSort(std::vector<T> &arr) {
        uzi RUN = 32;
        uzi n = arr.size();

        //std::cout << "insertionSort başı" << std::endl;
        // Sort individual subarrays of size RUN
        for (uzi i = 0; i < n; i += RUN) {
            insertionRSort(arr, i, std::min((i + RUN - 1), (n - 1)));
        }

        // start merging from size RUN (or 32). It will merge
        // to form size 64, then 128, 256 and so on ....
        for (uzi size = RUN; size < n; size = 2 * size) {
            // pick starting point of left sub array. We
            // are going to merge arr[left..left+size-1]
            // and arr[left+size, left+2*size-1]
            // After every merge, we increase left by 2*size
            for (uzi left = 0; left < n; left += 2 * size) {
                // find ending point of left sub array
                // mid+1 is starting point of right sub array
                uzi mid = left + size - 1;
                uzi right = std::min((left + 2 * size - 1), (n - 1));

                // merge sub array arr[left.....mid] &
                // arr[mid+1....right]
                mergeRSort(arr, left, mid, right);
            }
        }
    }
}
#endif // lxl_ALGO_SORT_TIMSORT_H_
