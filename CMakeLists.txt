cmake_minimum_required(VERSION 3.16)
project(lxl DESCRIPTION "C++ Utility Library")

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -fPIC -O3 -march=native")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -fPIC -O0")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS iostreams)

include_directories(${Boost_INCLUDE_DIRS})

include_directories(include)
include_directories(include/algo)
include_directories(include/algo/crypto)
include_directories(include/algo/sort)
include_directories(include/algo/string)
include_directories(include/compression)
include_directories(include/math)
include_directories(include/utils)
include_directories(include/vector)

add_library(lxl SHARED
        include/algo/crypto/hash.h
        include/algo/sort/insertionSort.h
        include/algo/sort/mergeSort.h
        include/algo/sort/selectionSort.h
        include/algo/sort/timSort.h
        include/algo/string/case.h
        include/algo/string/explode.h
        include/algo/string/cmath.h
        include/algo/string/trim.h
        include/algo/compare.h
        include/algo/crypto.h
        include/algo/distinct.h
        include/algo/noise.h
        include/algo/size.h
        include/algo/sort.h
        include/algo/cstring.h
        include/algo/swap.h
        include/compression/bzip2.h
        include/compression/gzip.h
        include/math/logic.h
        include/math/combination.h
        include/math/permutation.h
        include/math/random.h
        include/math/statistics.h
        include/math/utils.h
        include/utils/delete.h
        include/utils/fetchData.h
        include/utils/print.h
        include/utils/ctime.h
        include/vector/copy.h
        include/vector/create.h
        include/vector/dimension.h
        include/vector/cmath.h
        include/vector/print.h
        include/vector/size.h
        include/vector/statistics.h
        include/algo.h
        include/compression.h
        include/lxl.h
        include/utils/timer.h
        include/utils/type.h
        include/utils.h
        include/vector.h
        src/algo/string/case.cpp
        src/algo/string/explode.cpp
        src/algo/string/cmath.cpp
        src/algo/string/trim.cpp
        src/math/permutation.cpp
        src/math/statistics.cpp
        src/math/utils.cpp
        src/utils/shellExec.cpp
        src/utils/sleep.cpp
        src/utils/ctime.cpp)

target_link_libraries(lxl ${Boost_LIBRARIES})

# Change install prefix according to your system
set(CMAKE_INSTALL_PREFIX /usr/)

install(DIRECTORY include/. DESTINATION include/lxl)
install(TARGETS lxl LIBRARY DESTINATION lib)