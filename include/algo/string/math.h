#ifndef lxl_ALGO_STRING_MATH_H_
#define lxl_ALGO_STRING_MATH_H_

#include <string>

namespace lxl {
    bool isNumber(const std::string &s);

    double value(const std::string &s);

    double _value(const std::string &s);

    template<typename T> std::string roundStr(T x, uzi decimalPlaces)
    {
        std::string text = std::to_string(x);
        std::vector<std::string> textArray = explode(".",text);
        return textArray[0]+"."+textArray[1].substr(0,decimalPlaces);
    }
}
#endif // lxl_ALGO_STRING_MATH_H_
