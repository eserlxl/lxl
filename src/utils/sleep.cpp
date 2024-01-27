#include <chrono>
#include <thread>
#include <string>

namespace lxl {
    void sleep(std::size_t x, const std::string &unit) {
        if (unit == "s") {
            std::this_thread::sleep_for(std::chrono::seconds(x));
        } else if (unit == "ms") {
            std::this_thread::sleep_for(std::chrono::milliseconds(x));
        } else if (unit == "ns") {
            std::this_thread::sleep_for(std::chrono::nanoseconds(x));
        }
    }
}