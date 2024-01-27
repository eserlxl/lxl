#ifndef lxl_ALGO_SIZE_H_
#define lxl_ALGO_SIZE_H_

#include <iostream>
#include <type_traits>
#include <vector>
#include <iomanip>
#include <sstream>

namespace lxl {
    template<typename T>
    struct sizeMethodCheck {
    private:
        typedef std::true_type yes;
        typedef std::false_type no;

        template<typename U>
        static auto test(int) -> decltype(std::declval<U>().size() == 1, yes());

        template<typename>
        static no test(...);

    public:

        static constexpr bool available = std::is_same<decltype(test<T>(0)), yes>::value;
    };


//TODO: Write a general size function for all types.
    template<class A>
    std::size_t getSize(A array) {
        if (sizeMethodCheck<A>::available) {
            return array.size();
        } else {
            return -1;
        }
    }
}
#endif // lxl_ALGO_SIZE_H_
