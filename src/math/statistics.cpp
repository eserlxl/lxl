#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "utils.h"

namespace lxl {
    unsigned int entropy() {
        std::ifstream fp("/proc/sys/kernel/random/entropy_avail", std::ios::in);
        if (fp.is_open()) {
            std::string line;
            std::getline(fp, line);
            fp.close();

            return _value(line);
        } else {
            return 0;
        }
    }

    unsigned int sRand() {
        unsigned int e = entropy() + std::stoi(shellExec("vmstat -s|awk {'d=(d+$1)%525373;print d'}|tail -1"));

        srand(e);

        return e;
    }

// Gaussian / Normal Distribution
// In Gaussian Distribution mean = expectation = median = mode
    double normalD(double x, double mean, double stdDev) {
        return exp(-pow((x - mean), 2.) / (2 * stdDev * stdDev)) / (stdDev * sqrt(2. * M_PI));
    }

// Fibonacci Space
    long double fibonacciSpace(long double x) {
        long double goldenRatio;
        matrixLongDouble1D fibonacci;
        goldenRatio = 0.61803398875;
        //fibonacci = [ 0, 0.013150, 0.021290, 0.034440, 0.055729, 0.090169, 0.14590, 0.23607, 0.38197, 0.61803 ];

        fibonacci.push_back(0);
        for (int i = 9; i > -10; i--) {
            fibonacci.push_back(powl(goldenRatio, i));
        }

        int y = -1;
        for (long double i : fibonacci) {
            if (x >= i) {
                y++;
            }
        }

        return y + (x - fibonacci[y]) / (fibonacci[y + 1] - fibonacci[y]);
    }

    long double fibonacciValue(long double x, long double ma) {
        if (fabsl(ma) < 1e-12) {
            return 0;
        }

        if (x >= ma) {
            return fibonacciSpace(x / ma - 1);
        }

        return -fibonacciSpace(1 - x / ma);
    }
}