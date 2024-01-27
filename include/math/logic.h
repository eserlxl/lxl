#ifndef LXL_NN_LOGIC_H
#define LXL_NN_LOGIC_H

#include <cmath>
#include "utils.h"

namespace lxl {
/**
 * Sigmoid
 * Simple logistic function, It is a smooth, S-shaped curve.
 * Output: [0,1]
 */
    template<typename Float>
    Float sigmoid(Float x, Float a = 1) {
        return (Float) 1 / ((Float) 1 + std::exp(-a * x));
    }

    template<typename Float>
    Float dSigmoid(Float x, Float a = 1) {
        Float s = sigmoid(x, a);
        return s * ((Float) 1 - s);
    }

// Parametric Rectified Linear Unit ( Leaky ReLU )
// x<0?0:(x>1?1:x)
    template<typename Float>
    Float reLU(Float x) {
        return std::min(x > 0 ? x : Float(0.01) * x, (Float) 1);
    }

    template<typename Float>
    Float dReLU(Float x) {
        return x > 0 ? x : 0.01;
    }

// Inverse of sigmoid(x), x: [0,1]
    template<typename Float>
    Float logit(Float x, Float a = 0.995f) {
        return std::log(x / (1.f - std::min(a, x)));
    }
}
#endif //LXL_NN_LOGIC_H
