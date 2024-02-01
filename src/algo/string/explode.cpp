#include <vector>
#include <string>
#include <utility>
#include "utils.h"

namespace lxl {
    matrixString1D explode(const std::string &delimiter, const std::string &str) {
        matrixString1D arr;

        uzi strleng = str.length();
        uzi delleng = delimiter.length();
        if (delleng == 0)
            return arr;//no change

        uzi i = 0;
        uzi k = 0;
        while (i < strleng) {
            uzi j = 0;
            while (i + j < strleng && j < delleng && str[i + j] == delimiter[j])
                j++;
            if (j == delleng) //found delimiter
            {
                arr.push_back(str.substr(k, i - k));
                i += delleng;
                k = i;
            } else {
                i++;
            }
        }
        arr.push_back(str.substr(k, i - k));
        return arr;
    }

    matrixString1D explode(char delim, std::string const &s) {
        matrixString1D result;
        std::istringstream iss(s);

        for (std::string token; std::getline(iss, token, delim);) {
            result.push_back(std::move(token));
        }

        return result;
    }
}