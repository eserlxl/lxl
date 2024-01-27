#ifndef lxl_ALGO_NOISE_H
#define lxl_ALGO_NOISE_H

#include <cmath>
#include "vector.h"
#include "utils/delete.h"
#include "math/random.h"

namespace lxl {
    class noise {
    public:
        explicit noise(uzi seed = 2020, uzi randomVectorSize = 10, long double noisePower = 1) {
            auto *random = new Random();
            random->init(seed);
            for (uzi i = 0; i < std::max(randomVectorSize, (uzi) 2); i++) {
                r.push_back(random->generate());
            }
            safeDelete(random);

            this->noisePower = noisePower;
        }

        long double eval(long double x) {

            std::vector<long double> tempVec;
            for (uzi i = 0; i < r.size() - 1; i++) {
                long double u = powl(x, noisePower);
                tempVec.push_back((1. - x) * r[i] * u + (1 - u) * r[i + 1]);
            }
            long double minVal = min(tempVec)[0];
            long double maxVal = max(tempVec)[0];

            return (x - minVal) / (maxVal - minVal);
        }

        ~noise() = default;

        std::vector<long double> r;
        long double noisePower;
    };
}
#endif //lxl_ALGO_NOISE_H
