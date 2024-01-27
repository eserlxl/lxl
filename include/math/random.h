#ifndef lxl_MATH_RANDOM_H_
#define lxl_MATH_RANDOM_H_

#include <iostream>
#include <random>
#include <chrono>
#include "utils.h"
#include "math/statistics.h"

namespace lxl {
    class Random {
    public:
        std::random_device dev; // RDRND, /dev/urandom
        std::mt19937 rng;

        void timeInit() {
            rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        }

        void devInit() {
            rng.seed(dev());
        }

        void realInit() {
            rng.seed(sRand());
        }

        void init(uzi sRandNo) {
            rng.seed(sRandNo);
        }

        long double generate() {
            return Rand(rng);
        }

        template<typename T>
        T rand(T a, T b) {
            return a + generate() * (b - a);
        }

        Random() {
            devInit();
        }

        ~Random() {
        }

    private:
        std::uniform_real_distribution<long double> Rand;
        //std::uniform_int_distribution<std::mt19937::result_type> dist6 ( 1,6 );
        //std::uniform_int_distribution<uint32_t> uint_dist;         // by default range [0, MAX]
        //std::uniform_int_distribution<uint32_t> uint_dist10 ( 0,10 ); // range [0,10]
        //std::normal_distribution<double> normal_dist ( mean, stddeviation ); // N(mean, stddeviation)
    };
}
#endif // lxl_MATH_RANDOM_H_
