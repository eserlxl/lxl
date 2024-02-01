#ifndef lxl_ALGO_STRING_EXPLODE_H_
#define lxl_ALGO_STRING_EXPLODE_H_

#include <vector>
#include <string>

namespace lxl {
    matrixString1D explode(const std::string &delimiter, const std::string &str);

    matrixString1D explode(char delim, std::string const &s);
}
#endif // lxl_ALGO_STRING_EXPLODE_H_
