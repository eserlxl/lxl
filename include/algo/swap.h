#ifndef lxl_ALGO_SWAP_H_
#define lxl_ALGO_SWAP_H_

namespace lxl {
    template<typename T>
    void swap(T *xp, T *yp) {
        T temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
}
#endif // lxl_ALGO_SWAP_H_
