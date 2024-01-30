#ifndef lxl_VECTOR_PRINT_H_
#define lxl_VECTOR_PRINT_H_

#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "utils/type.h"
#include "vector/dimension.h"
#include "vector/size.h"
#include "algo/compare.h"

namespace lxl {
    template<typename T, typename S>
    void printHighPrecision(T x, uzi precision = 6, S &streamBuf = std::cout) {
        // Usage:
        // printHighPrecision(convert<long double>("0.123456789123456789123456789"),19,std::cout); -> 0.123456789123456789
        // printHighPrecision(convert<long double>("0.123456789"),19,std::cout); -> 0.123456789
        // printHighPrecision(convert<long double>("0.12345"),19,std::cout); -> 0.12345
        // printHighPrecision(convert<long double>("0.12"),19,std::cout); -> 0.12

        // Do we really need high precision?
        if ((long double) x - (float) x != 0) {
            streamBuf << std::setprecision(precision) << x;
        } else {
            streamBuf << x;
        }
    }

    template<typename T, typename S>
    void printVec(std::vector<T> v, uzi precision = 6, S &streamBuf = std::cout) {
        for (unsigned int i = 0; i < v.size(); i++) {
            printHighPrecision(v[i], precision, streamBuf);
            streamBuf << " ";
        }
        streamBuf << std::endl;
    }

    template<typename T, typename S>
    void printVec(std::vector<std::vector<T>> v, uzi precision = 6, S &streamBuf = std::cout) {
        for (unsigned int i = 0; i < v.size(); i++) {
            for (unsigned int j = 0; j < v[i].size(); j++) {
                printHighPrecision(v[i][j], precision, streamBuf);
                streamBuf << " ";
            }
            streamBuf << std::endl;
        }
    }

    template<typename T, typename S>
    void printVec(std::vector<std::vector<std::vector<T>>> v, uzi precision = 6, S &streamBuf = std::cout) {
        for (unsigned int i = 0; i < v.size(); i++) {
            for (unsigned int j = 0; j < v[0].size(); j++) {
                for (unsigned int k = 0; k < v[i][j].size(); k++) {
                    printHighPrecision(v[i][j][k], precision, streamBuf);
                    streamBuf << " ";
                }
                streamBuf << std::endl;
            }
            streamBuf << std::endl;
        }
    }

    template<class A>
    void print(A v, uzi precision = 6) {
        printVec(v, precision, std::cout);
    }

    template<class A, typename S>
    void print(A v, uzi precision = 6, S &streamBuf = std::cout) {
        printVec(v, precision, streamBuf);
    }

// dimension count, dimension-1 size,dimension-2 size,..., info
    template<class A, typename S>
    void printSize(A v, const std::string &text = "", S &streamBuf = std::cout) {
        std::string temp;

        std::vector<uzi> tempVec = sizeVec(v);

        uzi d = dimension(v);
        for (uzi i = 0; i < d; i++) {
            temp += std::to_string(tempVec[i]) + " ";
        }
        streamBuf << std::to_string(d) + " " + temp + text << std::endl;
    }

    template<class A, typename S>
    void print(A v, const std::string &text, uzi precision = 6, S &streamBuf = std::cout) {
        if (v.empty()) {
            streamBuf << "0 " + text << std::endl;
        } else {
            printSize(v, text, streamBuf);
            print(v, precision, streamBuf);
        }
    }
}
#endif // lxl_VECTOR_PRINT_H_
