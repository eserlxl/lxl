#ifndef lxl_MATH_STATISTICS_H_
#define lxl_MATH_STATISTICS_H_

#include <cmath>

namespace lxl {
// m options for General Mean function
#define RMS_MEAN 3
#define QUADRATIC_MEAN 2
#define ARITHMETIC_MEAN 1
#define GEOMETRIC_MEAN 0
#define HARMONIC_MEAN -1

    unsigned int entropy();

    unsigned int sRand();

    double normalD(double x, double mean, double stdDev);

#define gaussD normalD

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
    T mean(int m, int n, T *array) {
        T result;
        T temp = 0.;

        if (m != 0) {
            for (unsigned int i = 0; i < n; i++) {
                temp += powl(array[i], (T) m);
            }

            result = powl(temp / (T) n, 1. / (T) m);
        } else {
            temp = 1.;

            for (unsigned int i = 0; i < n; i++) {
                temp *= array[i];
            }

            result = powl(temp, 1. / (T) n);
        }

        return result;
    }

// Standard Deviation - Deviation from the mean
// [http://en.wikipedia.org/wiki/Standard_deviation]
    template<typename T>
    T stdDev(int n, T *array) {
        T o = mean(1, n, array);

        T array2[n];

        for (unsigned int i = 0; i < n; i++) {
            array2[i] = array[i] - o;
        }

        return mean(2, n, array2);
    }

// [http://en.wikipedia.org/wiki/Median]
    template<typename T>
    T median(int n, T *array) {
        if (n % 2 == 1) {
            return array[(n - 1) / 2];
        } else {
            return (array[n / 2 - 1] + array[n / 2]) / 2.;
        }
    }

    long double fibonacciSpace(long double x);

    long double fibonacciValue(long double x, long double ma);
}
#endif // lxl_MATH_STATISTICS_H_
