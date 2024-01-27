#include <cmath>

namespace lxl {
// int mod (%)
    double mod(double x, double mod) {
        return fmod(ceil(x), ceil(mod));
    }

    bool isInteger(double k) {
        return std::floor(std::abs(k)) == std::abs(k);
    }

    void dec2bin(unsigned long int dec,
                 ushort *bin, unsigned int length) {
        for (unsigned int i = 0; i < length; i++)
            *(bin++) = (dec >> i) & 0x1;
    }

    void bin2dec(const ushort *bin,
                 unsigned long int *dec, int length) {
        int i = length;
        *dec = 0;
        while (i--) {
            *dec <<= 1;
            *dec += *(bin + i);
        }
    }
}