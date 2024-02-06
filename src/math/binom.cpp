#include <iostream>
#include <vector>
#include "utils/type.h"
#include "algo.h"

namespace lxl {
    std::string binomTriangle(uzi index) {
        matrixUzi2D hayyam(index + 1);
        std::string hayyamTriangle;

        for (uzi i = 0; i <= index; i++) {
            for (uzi j = 0; j <= index - i; j++) {
                hayyamTriangle += "\t";
            }
            hayyam[i].resize(i + 1);
            hayyam[i][0] = 1;
            hayyamTriangle += roundStr(hayyam[i][0], 0) + "\t\t";
            for (uzi j = 1; j < i; j++) {
                hayyam[i][j] = hayyam[i - 1][j - 1] + hayyam[i - 1][j];
                hayyamTriangle += roundStr(hayyam[i][j], 0) + "\t\t";
            }
            hayyam[i][i] = 1;
            if (i > 0)hayyamTriangle += roundStr(hayyam[i][i], 0) + "\t\t";
            if (i < index)hayyamTriangle += "\n";
        }

        return hayyamTriangle;
    }

    matrixUzi2D binom(uzi index) {
        matrixUzi2D hayyam(index + 1);

        for (uzi i = 0; i <= index; i++) {
            hayyam[i].resize(i + 1);
            hayyam[i][0] = 1;
            for (uzi j = 1; j < i; j++) {
                hayyam[i][j] = hayyam[i - 1][j - 1] + hayyam[i - 1][j];
            }
            hayyam[i][i] = 1;
        }
        return hayyam;
    }
}