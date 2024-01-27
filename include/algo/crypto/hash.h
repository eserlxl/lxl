#ifndef lxl_ALGO_CRYPTO_HASH_H_
#define lxl_ALGO_CRYPTO_HASH_H_

#include <unordered_map>

namespace lxl {
    template<typename T>
    std::hash<T> hash(const T s) {
        return std::hash<T>(s);
    }
}
#endif // lxl_ALGO_CRYPTO_HASH_H_
