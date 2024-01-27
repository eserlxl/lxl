#include <cmath>
#include <limits>
#include "algo/string/trim.h"

namespace lxl {
    bool isNumber(const std::string &s) {
        std::string s2 = trim_copy(s);
        if (s.size() == s2.size() && !s2.empty()) {
            char *err;
            strtod(s2.c_str(), &err);
            return !(std::string(err).size());
        } else {
            return false;
        }
    }

// After isNumber check
    double value(const std::string &s) {
        char *err;
        double d = strtod(s.c_str(), &err);

        // Too Big number protection
        d += std::numeric_limits<double>::min();

        // Too Low number protection
        d = (1. + d) - 1;

        return d;
    }

// Including isNumber check
    double _value(const std::string &s) {
        if (isNumber(s)) {
            char *err;
            double d = strtod(s.c_str(), &err);

            // Too Big number protection
            d += std::numeric_limits<double>::min();

            // Too Low number protection
            d = (1. + d) - 1;

            return d;
        } else {
            return std::numeric_limits<double>::signaling_NaN();
        }
    }
}