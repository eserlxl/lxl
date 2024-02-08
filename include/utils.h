#ifndef lxl_UTILS_H_
#define lxl_UTILS_H_

#include <string>
#include "utils/type.h"
#include "utils/delete.h"
#include "utils/load.h"
#include "utils/print.h"
#include "utils/timer.h"

namespace lxl {
    std::string shellExec(const char *cmd);

    void sleep(std::size_t x, std::string unit);
}

#endif // lxl_UTILS_H_
