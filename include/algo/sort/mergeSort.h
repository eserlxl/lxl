#ifndef lxl_ALGO_SORT_MERGESORT_H_
#define lxl_ALGO_SORT_MERGESORT_H_

#include <vector>
#include "type.h"

namespace lxl {
    template<typename T>
    void mergeSort(T arr[], uzi l, uzi m, uzi r) {
        // original array is broken in two parts
        // left and right array
        uzi len1 = std::max((uzi) 0, m - l + 1), len2 = std::max((uzi) 0, r - m);

        std::vector<T> left(std::max((uzi) 0, len1)), right(std::max((uzi) 0, len2));

        for (uzi i = 0; i < len1; i++)
            left[i] = arr[l + i];
        for (uzi i = 0; i < len2; i++)
            right[i] = arr[m + 1 + i];

        uzi i = 0;
        uzi j = 0;
        uzi k = l;

        // after comparing, we merge those two array
        // in larger sub array
        while (i < len1 && j < len2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        // copy remaining elements of left, if any
        while (i < len1) {
            arr[k] = left[i];
            k++;
            i++;
        }

        // copy remaining element of right, if any
        while (j < len2) {
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    template<typename T>
    void mergeSort(std::vector<T> &arr, uzi l, uzi m, uzi r) {
        // original array is broken in two parts
        // left and right array
        uzi len1 = std::max((uzi) 0, m - l + 1), len2 = std::max((uzi) 0, r - m);

        std::vector<T> left(std::max((uzi) 0, len1)), right(std::max((uzi) 0, len2));

        for (uzi i = 0; i < len1; i++)
            left[i] = arr[l + i];
        for (uzi i = 0; i < len2; i++)
            right[i] = arr[m + 1 + i];

        uzi i = 0;
        uzi j = 0;
        uzi k = l;

        // after comparing, we merge those two array
        // in larger sub array
        while (i < len1 && j < len2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        // copy remaining elements of left, if any
        while (i < len1) {
            arr[k] = left[i];
            k++;
            i++;
        }

        // copy remaining element of right, if any
        while (j < len2) {
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    template<typename T>
    void mergeRSort(T arr[], uzi l, uzi m, uzi r) {
        // original array is broken in two parts
        // left and right array
        uzi len1 = std::max((uzi) 0, m - l + 1), len2 = std::max((uzi) 0, r - m);

        std::vector<T> left(std::max((uzi) 0, len1)), right(std::max((uzi) 0, len2));

        for (uzi i = 0; i < len1; i++)
            left[i] = arr[l + i];
        for (uzi i = 0; i < len2; i++)
            right[i] = arr[m + 1 + i];

        uzi i = 0;
        uzi j = 0;
        uzi k = l;

        // after comparing, we merge those two array
        // in larger sub array
        while (i < len1 && j < len2) {
            if (left[i] > right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        // copy remaining elements of left, if any
        while (i < len1) {
            arr[k] = left[i];
            k++;
            i++;
        }

        // copy remaining element of right, if any
        while (j < len2) {
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    template<typename T>
    void mergeRSort(std::vector<T> &arr, uzi l, uzi m, uzi r) {
        // original array is broken in two parts
        // left and right array
        uzi len1 = std::max((uzi) 0, m - l + 1), len2 = std::max((uzi) 0, r - m);

        std::vector<T> left(std::max((uzi) 0, len1)), right(std::max((uzi) 0, len2));

        for (uzi i = 0; i < len1; i++)
            left[i] = arr[l + i];
        for (uzi i = 0; i < len2; i++)
            right[i] = arr[m + 1 + i];

        uzi i = 0;
        uzi j = 0;
        uzi k = l;

        // after comparing, we merge those two array
        // in larger sub array
        while (i < len1 && j < len2) {
            if (left[i] > right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        // copy remaining elements of left, if any
        while (i < len1) {
            arr[k] = left[i];
            k++;
            i++;
        }

        // copy remaining element of right, if any
        while (j < len2) {
            arr[k] = right[j];
            k++;
            j++;
        }
    }

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
    template<typename T>
    void mergeSort(T *arr, uzi l, uzi r) {
        if (l < r) {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            uzi m = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            mergeSort(arr, l, m, r);
        }
    }

    template<typename T>
    void mergeSort(std::vector<T> &arr, uzi l, uzi r) {
        if (l < r) {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            uzi m = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            mergeSort(arr, l, m, r);
        }
    }

    template<typename T>
    void mergeRSort(T *arr, uzi l, uzi r) {
        if (l < r) {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            uzi m = l + (r - l) / 2;

            // Sort first and second halves
            mergeRSort(arr, l, m);
            mergeRSort(arr, m + 1, r);

            mergeRSort(arr, l, m, r);
        }
    }

    template<typename T>
    void mergeRSort(std::vector<T> &arr, uzi l, uzi r) {
        if (l < r) {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            uzi m = l + (r - l) / 2;

            // Sort first and second halves
            mergeRSort(arr, l, m);
            mergeRSort(arr, m + 1, r);

            mergeRSort(arr, l, m, r);
        }
    }

    template<typename T>
    void mergeSort(std::vector<T> &arr) {
        int r = arr.size() - 1;
        if (0 < r) {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            uzi m = r / 2;

            // Sort first and second halves
            mergeSort(arr, 0, m);
            mergeSort(arr, m + 1, r);

            mergeSort(arr, 0, m, r);
        }
    }

    template<typename T>
    void mergeRSort(std::vector<T> &arr) {
        int r = arr.size() - 1;
        if (0 < r) {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            uzi m = r / 2;

            // Sort first and second halves
            mergeRSort(arr, 0, m);
            mergeRSort(arr, m + 1, r);

            mergeRSort(arr, 0, m, r);
        }
    }
}
#endif // lxl_ALGO_SORT_MERGESORT_H_
