#include <algorithm>
#include <cctype>
#include <string>

namespace lxl {
    std::string lowerCase(const std::string &source) {
        std::string data = source;
        std::transform(data.begin(), data.end(), data.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        return data;
    }

    std::string upperCase(const std::string &source) {
        std::string data = source;
        std::transform(data.begin(), data.end(), data.begin(),
                       [](unsigned char c) { return std::toupper(c); });

        return data;
    }
}