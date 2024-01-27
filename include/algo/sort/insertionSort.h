#ifndef lxl_ALGO_SORT_INSERTIONSORT_H_
#define lxl_ALGO_SORT_INSERTIONSORT_H_

#include <vector>
#include "utils.h"

namespace lxl {
// Sorts array from left index to right
    template<typename T>
    void insertionSort(T arr[], uzi left, uzi right) {
        for (uzi i = left + 1; i <= right; i++) {
            T temp = arr[i];
            int j = (int) i - 1;
            while (arr[j] > temp && j >= left) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

// Sorts array from left index to right
    template<typename T>
    void insertionSort(std::vector<T> &arr, uzi left, uzi right) {
        for (uzi i = left + 1; i <= right; i++) {
            T temp = arr[i];
            int j = (int) i - 1;
            while (arr[j] > temp && j >= (int) left) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    template<typename T>
    void insertionSort(T arr[], uzi n) {
        for (uzi i = 1; i < n; i++) {
            T temp = arr[i];
            int j = (int) i - 1;
            while (arr[j] > temp && j >= 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    template<typename T>
    void insertionSort(std::vector<T> &arr) {
        for (uzi i = 1; i < arr.size(); i++) {
            T temp = arr[i];
            int j = (int) i - 1;
            while (arr[j] > temp && j >= 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }


// Sorts array from left index to right
    template<typename T>
    void insertionRSort(T arr[], uzi left, uzi right) {
        for (uzi i = left + 1; i <= right; i++) {
            T temp = arr[i];
            int j = (int) i - 1;
            while (arr[j] < temp && j >= (int) left) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

// Sorts array from left index to right
    template<typename T>
    void insertionRSort(std::vector<T> &arr, uzi left, uzi right) {
        for (uzi i = left + 1; i <= right; i++) {
            T temp = arr[i];
            int j = (int) i - 1;
            while (arr[j] < temp && j >= (int) left) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    template<typename T>
    void insertionRSort(T arr[], uzi n) {
        for (uzi i = 1; i < n; i++) {
            T temp = arr[i];
            int j = (int) i - 1;
            while (arr[j] < temp && j >= 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    template<typename T>
    void insertionRSort(std::vector<T> &arr) {
        for (uzi i = 1; i < arr.size(); i++) {
            T temp = arr[i];
            int j = (int) i - 1;
            while (arr[j] < temp && j >= 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
}
#endif // lxl_ALGO_SORT_INSERTIONSORT_H_
