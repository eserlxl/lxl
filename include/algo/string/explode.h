#ifndef lxl_ALGO_STRING_EXPLODE_H_
#define lxl_ALGO_STRING_EXPLODE_H_

#include <vector>
#include <string>

namespace lxl {
    std::vector<std::string> explode(const std::string &delimiter, const std::string &str);

    std::vector<std::string> explode(char delim, std::string const &s);
}
#endif // lxl_ALGO_STRING_EXPLODE_H_
