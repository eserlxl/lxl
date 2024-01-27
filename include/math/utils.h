#ifndef lxl_MATH_UTILS_H_
#define lxl_MATH_UTILS_H_

#include <cmath>
#include <iostream>

namespace lxl {
    template<typename T1, typename T2, typename T3>
    T1 bound(T1 x, T2 low, T3 high) {
        if (low > high) {
            T1 g;
            g = high;
            high = low;
            low = g;
        }
        if (x < low)
            x = low;
        else if (x > high)
            x = high;
        return x;
    }

    template<typename T1, typename T2, typename T3>
    T1 limit(T1 x, T2 low, T3 high) {
        if (x < low)
            x = low;
        else if (x > high)
            x = high;
        return x;
    }

    template<typename T>
    int sign(T x) {
        if (x == (T) 0) {
            return 0;
        } else {
            return x > 0 ? 1 : -1;
        }
    }

    template<typename T>
    T max(T x, T y) {
        return x > y ? x : y;
    }

    template<typename T>
    T min(T x, T y) {
        return x < y ? x : y;
    }

    template<typename T, typename U>
    auto max(T x, U y) -> decltype(x > y ? x : y) {
        return x > y ? x : y;
    }

    template<typename T, typename U>
    auto min(T x, U y) -> decltype(x < y ? x : y) {
        return x < y ? x : y;
    }

    template<typename T>
    unsigned int digitNum(T a, unsigned int base) {
        T b = a;
        unsigned int k = 0;

        if (b == 0) return 1;

        while (b >= 1) {
            b /= base;
            k++;
        }
        return k;
    }

    template<typename T>
    unsigned int digitNum(T a) {
        T b = a;
        unsigned int k = 0;

        if (b == 0) return 1;

        while (b >= 1) {
            b /= 10;
            k++;
        }
        return k;
    }

    template<class T>
    T round(T value, int decimalPlaces) {
        static_assert(std::is_floating_point<T>::value, "round<T>: T must be floating point");

        const T shift = powl(10.l, decimalPlaces);

        return round(value * shift) / shift;
    }

    template<class T>
    std::string decimal2Base(long double x, T targetBase, int digit = 12) {
        std::string base;
        while (digit > 0) {
            long double y = powl(targetBase, digit - 1);
            if (y <= x) {
                x -= y;
                base += "1";
            } else {
                base += "0";
            }
            digit--;
        }
        return base;
    }

    template<class T>
    long double base2Decimal(std::string &x, T sourceBase) {
        std::string base;
        int l = x.length();
        long double y = 0;
        for (int i = 0; i < l; i++) {
            char z = '0';
            y += (x[i] - z) * pow(sourceBase, l - i - 1);
        }
        return y;
    }

    double mod(double x, double mod);

    void dec2bin(unsigned long int dec,
                 ushort *bin, unsigned int length);

    void bin2dec(const ushort *bin,
                 unsigned long int *dec, int length);

}
#endif // lxl_MATH_UTILS_H_
