#ifndef lxl_VECTOR_MATH_H_
#define lxl_VECTOR_MATH_H_

#include <vector>
#include <limits>
#include <ctgmath>
#include "vector.h"
#include "math/utils.h"
#include "utils/type.h"

namespace lxl {
    template<typename Float>
    Float mulVec(std::vector<Float> &array1, std::vector<Float> &array2) {
        Float sum = 0;
        for (uzi i = 0; i < array1.size(); i++) {
            sum += array1[i] * array2[i];
        }

        return sum;
    }

    template<typename Float>
    std::vector<Float> add(std::vector<Float> &array1, std::vector<Float> &array2) {
        std::vector<Float> array;
        for (uzi i = 0; i < array1.size(); i++) {
            array.push_back(array1[i] + array2[i]);
        }

        return array;
    }

    template<typename Float>
    std::vector<Float> diff(std::vector<Float> &array1, std::vector<Float> &array2) {
        std::vector<Float> array;
        for (uzi i = 0; i < array1.size(); i++) {
            array.push_back(array1[i] - array2[i]);
        }

        return array;
    }

    template<typename Float>
    std::vector<std::vector<Float>>
    add(std::vector<std::vector<Float>> &array1, std::vector<std::vector<Float>> &array2) {
        std::vector<std::vector<Float>> array;
        for (uzi i = 0; i < array1.size(); i++) {
            std::vector<Float> temp;
            for (uzi j = 0; j < array1[i].size(); j++) {
                temp.push_back(array1[i][j] + array2[i][j]);
            }

            array.push_back(temp);
        }

        return array;
    }

    template<typename Float>
    std::vector<std::vector<Float>>
    diff(std::vector<std::vector<Float>> &array1, std::vector<std::vector<Float>> &array2) {
        std::vector<std::vector<Float>> array;
        for (uzi i = 0; i < array1.size(); i++) {
            std::vector<Float> temp;
            for (uzi j = 0; j < array1[i].size(); j++) {
                temp.push_back(array1[i][j] - array2[i][j]);
            }

            array.push_back(temp);
        }

        return array;
    }

    template<typename Float>
    Float sumVec(std::vector<Float> &array) {
        Float sum = 0;
        for (uzi i = 0; i < array.size(); i++) {
            sum += array[i];
        }

        return sum;
    }

// power = 0 => a + b + c + ...
// power = 1 => a + 2*b + 3*c + ...
// power = 2 => a + 4*b + 9*c + ...
// power = n => pow(1,n)*a + pow(2,n)*b + pow(3,n)*c + ...
    template<typename Float>
    Float sumVec(std::vector<Float> &array, Float power) {
        Float sum = 0;
        for (uzi i = 0; i < array.size(); i++) {
            sum += std::pow(i + 1, power) * array[i];
        }

        return sum;
    }

    template<typename Float>
    Float sum(std::vector<Float> &array) {
        return sumVec(array);
    }

    template<typename Float>
    Float sum(std::vector<Float> &array, Float power) {
        return sumVec(array, power);
    }

    template<typename Float>
    std::vector<std::vector<Float>> mul(std::vector<std::vector<Float>> &array, Float x) {
        std::vector<std::vector<Float>> result(array.size());

        for (uzi i = 0; i < array.size(); i++) {
            result[i].resize(array[i].size());
            for (uzi j = 0; j < array[i].size(); j++) {
                result[i][j] = array[i][j] * x;
            }
        }

        return result;
    }

    template<typename Float>
    std::vector<Float> mul(std::vector<Float> &array, Float x) {
        std::vector<Float> result(array.size());

        for (uzi i = 0; i < array.size(); i++) {
            result[i] = array[i] * x;
        }

        return result;
    }

    template<typename Float>
    Float mul(std::vector<Float> &array1, std::vector<Float> &array2) {
        return mulVec(array1, array2);
    }

    template<typename T>
    std::vector<T> max(std::vector<T> &array) {
        T maxElement = -std::numeric_limits<T>::max();
        unsigned int maxElementIndex = 0;
        for (unsigned int i = 0; i < array.size(); i++) {
            if (maxElement < array[i]) {
                maxElement = array[i];
                maxElementIndex = i;
            }
        }

        return {maxElement, (T) maxElementIndex};
    }

    template<typename T>
    std::vector<T> max(std::vector<std::vector<T>> &array) {
        T maxElement = -std::numeric_limits<T>::max();
        unsigned int maxElementIndexRow = 0;
        unsigned int maxElementIndexCol = 0;
        for (unsigned int i = 0; i < array.size(); i++) {
            for (unsigned int j = 0; j < array[i].size(); j++) {
                if (maxElement < array[i][j]) {
                    maxElement = array[i][j];
                    maxElementIndexRow = i;
                    maxElementIndexCol = j;
                }
            }
        }

        return {maxElement, (T) maxElementIndexRow, (T) maxElementIndexCol};
    }

    template<typename T>
    std::vector<T> min(std::vector<T> &array) {
        T minElement = std::numeric_limits<T>::max();
        unsigned int minElementIndex = 0;
        for (unsigned int i = 0; i < array.size(); i++) {
            if (minElement > array[i]) {
                minElement = array[i];
                minElementIndex = i;
            }
        }

        return {minElement, (T) minElementIndex};
    }

    template<typename T>
    std::vector<T> min(std::vector<std::vector<T>> &array) {
        T minElement = std::numeric_limits<T>::max();
        unsigned int minElementIndexRow = 0;
        unsigned int minElementIndexCol = 0;
        for (unsigned int i = 0; i < array.size(); i++) {
            for (unsigned int j = 0; j < array[i].size(); j++) {
                if (minElement > array[i][j]) {
                    minElement = array[i][j];
                    minElementIndexRow = i;
                    minElementIndexCol = j;
                }
            }
        }

        return {minElement, (T) minElementIndexRow, (T) minElementIndexCol};
    }

    template<typename T>
    std::vector<T> normal(std::vector<T> &array) {
        std::vector<T> nArray(array.size());

        T arrayMin = min(array)[0];
        T arrayMax = max(array)[0];

        if (arrayMin == arrayMax) {
            return array;
        } else {
            for (unsigned int i = 0; i < array.size(); i++) {
                nArray[i] = (array[i] - arrayMin) / (arrayMax - arrayMin);
            }
        }

        return nArray;
    }

    template<typename T>
    std::vector<T> normal(std::vector<T> &source, std::vector<T> &target) {
        target.resize(source.size());

        T arrayMin = min(source)[0];
        T arrayMax = max(source)[0];

        if (arrayMin == arrayMax) {
            //fill(target, (T) 1);
            for (unsigned int i = 0; i < source.size(); i++) {
                target[i] = 1;
            }
        } else {
            for (unsigned int i = 0; i < source.size(); i++) {
                target[i] = (source[i] - arrayMin) / (arrayMax - arrayMin);
            }
        }

        return {arrayMin, arrayMax};
    }

    template<typename T>
    std::vector<T> normal(std::vector<std::vector<T>> &source, std::vector<std::vector<T>> &target) {
        copy(source, target);

        T arrayMin = min(source)[0];
        T arrayMax = max(source)[0];

        for (unsigned int i = 0; i < source.size(); i++) {
            for (unsigned int j = 0; j < source[i].size(); j++) {
                if (arrayMin == arrayMax) {
                    target[i][j] = 1;
                } else {
                    target[i][j] = (source[i][j] - arrayMin) / (arrayMax - arrayMin);

                }
            }
        }

        return {arrayMin, arrayMax};
    }

    template<typename T>
    std::vector<T> normal(std::vector<T> &source, std::vector<T> &target, T rangeMin, T rangeMax) {
        target.resize(source.size());

        T arrayMin = min(source)[0];
        T arrayMax = max(source)[0];

        if (arrayMin == arrayMax) {
            //fill(target, (T) 1);
            for (unsigned int i = 0; i < source.size(); i++) {
                target[i] = 1;
            }
        } else {
            for (unsigned int i = 0; i < source.size(); i++) {
                target[i] = (rangeMax - rangeMin) * (source[i] - arrayMin) / (arrayMax - arrayMin) + rangeMin;
            }
        }

        return {arrayMin, arrayMax};
    }

    template<typename T>
    std::vector<T>
    normal(std::vector<std::vector<T>> &source, std::vector<std::vector<T>> &target, T rangeMin, T rangeMax) {
        copy(source, target);

        T arrayMin = min(source)[0];
        T arrayMax = max(source)[0];

        for (unsigned int i = 0; i < source.size(); i++) {
            for (unsigned int j = 0; j < source[i].size(); j++) {
                if (arrayMin == arrayMax) {
                    target[i][j] = 1;
                } else {
                    target[i][j] = (rangeMax - rangeMin) * (source[i][j] - arrayMin) / (arrayMax - arrayMin) + rangeMin;

                }
            }
        }

        return {arrayMin, arrayMax};
    }

    template<typename T>
    std::vector<T> abs(std::vector<T> &source) {
        std::vector<T> target;
        target.resize(source.size());

        for (uzi i = 0; i < source.size(); i++) {
            target[i] = std::abs(source[i]);
        }

        return target;
    }

    template<typename T>
    std::vector<std::vector<T>> abs(std::vector<std::vector<T>> &source) {
        std::vector<std::vector<T>> target;

        for (uzi i = 0; i < source.size(); i++) {
            target.push_back(abs(source[i]));
        }

        return target;
    }

    template<typename T>
    std::vector<T> round(std::vector<T> &source, T n) {
        std::vector<T> target;
        target.resize(source.size());

        for (unsigned int i = 0; i < source.size(); i++) {
            target[i] = round(source[i], n);
        }

        return target;
    }

    template<typename T>
    std::vector<std::vector<T>> round(std::vector<std::vector<T>> &source, T n) {
        std::vector<std::vector<T>> target;

        for (unsigned int i = 0; i < source.size(); i++) {
            target.push_back(round(source[i]), n);
        }

        return target;
    }

    template<typename T>
    T mean(std::vector<T> &array) {
        return sum(array) / array.size();
    }

/*
 [http://en.wikipedia.org/wiki/Mean]

 General Mean function
 ---------------------
 m-->infty  maximum
 m=2        quadratic mean
 m=1        arithmetic mean
 m-->0      geometric mean
 m=-1       harmonic mean
 m-->-infty  minimum
*/
    template<typename T>
    T mean(std::vector<T> &array, int type) {
        T result;
        T temp = (T) 0;

        unsigned int n = array.size();

        if (type != 0) {
            for (unsigned int i = 0; i < n; i++) {
                temp += std::pow(array[i], (T) type);
            }

            result = std::pow(temp / (T) n, (T) 1 / (T) type);
        } else {
            temp = (T) 1;

            for (unsigned int i = 0; i < n; i++) {
                temp *= array[i];
            }

            result = std::pow(temp, (T) 1 / (T) n);
        }

        return result;
    }

    template<typename T>
    T hypotenusMean(std::vector<T> array, T power) {
        T result;
        T temp = (T) 0;

        int n = array.size();

        if (power != 0) {
            for (int i = 0; i < n; i++) {
                temp += std::pow(array[i], power);
            }

            result = std::pow(temp, (T) 1 / power);
        } else {
            temp = (T) 1;

            for (int i = 0; i < n; i++) {
                temp *= array[i];
            }

            result = temp;
        }

        return result;
    }

    /**
     * Calculates the distance between two coordinate vectors.
     */
    template<typename T>
    T distance(std::vector<T> coordVec1, std::vector<T> coordVec2) {
        std::vector<T> temp;

        for (uzi i = 0; i < coordVec1.size(); i++) {
            temp.push_back(coordVec1[i] - coordVec2[i]);
        }

        return hypotenusMean(temp, (T) 2);
    }

    template<typename T>
    T rms(std::vector<std::vector<T>> &array) {
        T temp = (T) 0;

        uzi n = 0;
        for (int i = 0; i < array.size(); i++) {
            for (int j = 0; j < array[i].size(); j++) {
                temp += std::pow(array[i][j], (T) 2);
                n++;
            }
        }

        return std::sqrt(temp / (T) n);
    }

    template<typename T>
    T rms(std::vector<T> &array) {
        T temp = 0.;

        int n = array.size();

        for (int i = 0; i < n; i++) {
            temp += std::pow(array[i], (T) 2);
        }

        return std::sqrt(temp / (T) n);
    }

// Standard Deviation - Deviation from the mean
// [http://en.wikipedia.org/wiki/Standard_deviation]
    template<typename T>
    T stdDev(std::vector<T> &array) {
        uzi n = array.size();

        T o = mean(array, (T) 1);

        std::vector<T> array2(n);

        for (int i = 0; i < n; i++) {
            array2[i] = array[i] - o;
        }

        return mean(array2, (T) 2);
    }

// [http://en.wikipedia.org/wiki/Median]
    template<typename T>
    T median(std::vector<T> array) {
        unsigned int n = array.size();

        if (n % 2 == 1) {
            return array[(n - 1) / 2];
        } else {
            return (array[n / 2 - 1] + array[n / 2]) / (T) 2;
        }
    }
}
#endif // lxl_VECTOR_MATH_H_
