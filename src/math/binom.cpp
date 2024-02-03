#include <iostream>
#include <vector>
#include "utils/type.h"
#include "algo.h"

namespace lxl {
    std::string binomTriangle(uzi size) {
        matrixUzi2D hayyam;
        hayyam.resize(0, std::vector<uzi>(0));
        hayyam.resize(size * 2, std::vector<uzi>(size * 2));

        std::string hayyamTriangle;
        hayyam[0][0] = 1;
        for (uzi i = 0; i <= size; i++) {
            for (uzi j = 0; j <= size - i; j++) {
                hayyamTriangle += "\t";
            }

            hayyam[i][0] = 1;
            for (uzi j = 0; j <= i; j++) {
                if (j > 0 && i > 0) {
                    hayyam[i][j] = hayyam[i - 1][j - 1] + hayyam[i - 1][j];
                }
                hayyamTriangle += roundStr(hayyam[i][j], 0) + "\t\t";
            }
            if (i < size)hayyamTriangle += "\n";
        }
        return hayyamTriangle;
    }

    matrixUzi2D binom(uzi size) {
        matrixUzi2D hayyam;
        hayyam.resize(0, matrixUzi1D(0));
        hayyam.resize(size * 2, matrixUzi1D(size * 2));

        hayyam[0][0] = 1;
        for (uzi i = 0; i <= size; i++) {
            hayyam[i][0] = 1;
            for (uzi j = 0; j <= i; j++) {
                if (j > 0 && i > 0) {
                    hayyam[i][j] = hayyam[i - 1][j - 1] + hayyam[i - 1][j];
                }
            }
        }
        return hayyam;
    }
}