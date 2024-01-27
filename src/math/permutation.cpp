// https://rosettacode.org/wiki/Permutations#version_4

#include <iostream>
#include <vector>
#include "utils/type.h"

namespace lxl {
/* print a list of ints */
    int show(std::vector<uzi> x, uzi len) {
        for (uzi i = 0; i < len; i++)
            std::cout << x[i] << (i == len - 1 ? '\n' : ' ');
        return 1;
    }

/* next lexicographical permutation */
    int next_lex_perm(std::vector<uzi> a, uzi n) {
#	define swap(i, j) {t = a[i]; a[i] = a[j]; a[j] = t;}
        int k, l, t;

        /* 1. Find the largest index k such that a[k] < a[k + 1]. If no such
              index exists, the permutation is the last permutation. */
        for (k = n - 1; k && a[k - 1] >= a[k]; k--);
        if (!k--) return 0;

        /* 2. Find the largest index l such that a[k] < a[l]. Since k + 1 is
           such an index, l is well defined */
        for (l = n - 1; a[l] <= a[k]; l--);

        /* 3. Swap a[k] with a[l] */
        swap (k, l);

        /* 4. Reverse the sequence from a[k + 1] to the end */
        for (k++, l = n - 1; l > k; l--, k++) swap (k, l);
        return 1;
#	undef swap
    }

    void perm1(std::vector<uzi> x, uzi n, uzi callback(std::vector<uzi>, uzi)) {
        do {
            if (callback) callback(x, n);
        } while (next_lex_perm(x, n));
    }

/* Boothroyd method; exactly N! swaps, about as fast as it gets */
    void boothroyd(std::vector<uzi> x, uzi n, uzi nn, uzi callback(std::vector<uzi>, uzi)) {
        uzi c = 0, i, t;
        while (true) {
            if (n > 2) boothroyd(x, n - 1, nn, callback);
            if (c >= n - 1) return;

            i = (n & 1) ? 0 : c;
            c++;
            t = x[n - 1], x[n - 1] = x[i], x[i] = t;
            if (callback) callback(x, nn);
        }
    }

/* entry for Boothroyd method */
    void perm2(std::vector<uzi> x, uzi n, uzi callback(std::vector<uzi>, uzi)) {
        if (callback) callback(x, n);
        boothroyd(x, n, n, callback);
    }

    void boothroyd(std::vector<uzi> x, uzi n, std::vector<std::vector<uzi>> &y) {
        uzi c = 0, i, t;
        while (true) {
            if (n > 2) boothroyd(x, n - 1, y);
            if (c >= n - 1) return;

            i = (n & 1) ? 0 : c;
            c++;
            t = x[n - 1], x[n - 1] = x[i], x[i] = t;

            y.push_back(x);
        }
    }

/* entry for Boothroyd method */
    void perm(std::vector<uzi> x, uzi n, std::vector<std::vector<uzi>> &y) {
        boothroyd(x, n, y);
    }

/* same as perm2, but flattened recursions into iterations */
    void perm3(std::vector<uzi> x, uzi n, uzi callback(std::vector<uzi>, uzi)) {
        /* calloc isn't strictly necessary, int c[32] would suffice
           for most practical purposes */
        uzi d, i, t;
        std::vector<uzi> c(n);

        /* curiously, with GCC 4.6.1 -O3, removing next line makes
           it ~25% slower */
        if (callback) callback(x, n);
        for (d = 1;; c[d]++) {
            while (d > 1) c[--d] = 0;
            while (c[d] >= d)
                if (++d >= n) return;

            t = x[i = (d & 1) ? c[d] : 0], x[i] = x[d], x[d] = t;
            if (callback) callback(x, n);
        }
    }
}