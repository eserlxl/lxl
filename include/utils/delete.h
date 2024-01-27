#ifndef lxl_UTILS_DELETE_H
#define lxl_UTILS_DELETE_H

#include <iostream>
#include <vector>
#include "utils.h"

namespace lxl {
    template<class A>
    void deleteSafe(A &c) {
        if (c != NULL) {
            delete c;
            c = NULL;
        }
    }

    template<class A>
    void deleteSafe(std::vector<std::vector<std::vector<A>>> &c) {
        for (auto i:c) {
            deleteSafe(i);
        }
    }

    template<class A>
    void deleteSafe(std::vector<std::vector<A>> &c) {
        uzi size = c.size();
        for (uzi i = 0; i < size; i++) {
            uzi innerSize = c[i].size();
            for (uzi j = 0; j < innerSize; j++) {
                if (c[i][j] != NULL) {
                    delete c[i][j];
                    c[i][j] = NULL;
                }
            }
        }
    }

    template<class A>
    void deleteSafe(std::vector<A> &c) {
        uzi size = c.size();
        for (uzi i = 0; i < size; i++) {
            if (c[i] != NULL) {
                delete c[i];
                c[i] = NULL;
            }
        }
    }

    template<class A>
    void safeDelete(std::vector<std::vector<std::vector<A>>> &c) {
        deleteSafe(c);
    }

    template<class A>
    void safeDelete(std::vector<std::vector<A>> &c) {
        deleteSafe(c);
    }

    template<class A>
    void safeDelete(std::vector<A> &c) {
        deleteSafe(c);
    }

    template<class A>
    void safeDelete(A &c) {
        deleteSafe(c);
    }
}
#endif //LXL_DELETE_H
