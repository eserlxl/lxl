#include <vector>
#include <string>
#include <utility>
#include "type.h"

namespace lxl {
    std::vector<std::string> explode(const std::string &delimiter, const std::string &str) {
        std::vector<std::string> arr;

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

    std::vector<std::string> explode(char delim, std::string const &s) {
        std::vector<std::string> result;
        std::istringstream iss(s);

        for (std::string token; std::getline(iss, token, delim);) {
            result.push_back(std::move(token));
        }

        return result;
    }
}