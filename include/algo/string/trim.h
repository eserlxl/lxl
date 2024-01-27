#ifndef lxl_ALGO_STRING_TRIM_H_
#define lxl_ALGO_STRING_TRIM_H_

#include <string>

namespace lxl {
// trim from start (in place)
    void ltrim(std::string &s);

// trim from end (in place)
    void rtrim(std::string &s);

// trim from both ends (in place)
    void trim(std::string &s);

// trim from start (copying)
    std::string ltrim_copy(std::string s);

// trim from end (copying)
    std::string rtrim_copy(std::string s);

// trim from both ends (copying)
    std::string trim_copy(std::string s);
}
#endif // lxl_ALGO_STRING_TRIM_H_
