#ifndef lxl_TYPES_H_
#define lxl_TYPES_H_

#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <sstream>

namespace lxl {
    typedef std::size_t uzi;

    template<class A>
    std::string type(const A &) {
        typedef typename std::remove_all_extents<A>::type Type;

        if (typeid(uzi) == typeid(Type)) {
            return "uzi";
        } else if (typeid(bool) == typeid(Type)) {
            return "bool";
        } else if (typeid(int) == typeid(Type)) {
            return "int";
        } else if (typeid(unsigned int) == typeid(Type)) {
            return "unsigned int";
        } else if (typeid(long int) == typeid(Type)) {
            return "long int";
        } else if (typeid(unsigned long int) == typeid(Type)) {
            return "unsigned long int";
        } else if (typeid(long long int) == typeid(Type)) {
            return "long long int";
        } else if (typeid(unsigned long long int) == typeid(Type)) {
            return "unsigned long long int";
        } else if (typeid(float) == typeid(Type)) {
            return "float";
        } else if (typeid(double) == typeid(Type)) {
            return "double";
        } else if (typeid(long double) == typeid(Type)) {
            return "long double";
        } else if (typeid(char) == typeid(Type)) {
            return "char";
        } else if (typeid(unsigned char) == typeid(Type)) {
            return "unsigned char";
        } else if (typeid(char *) == typeid(Type)) {
            return "char*";
        } else if (typeid(char **) == typeid(Type)) {
            return "char**";
        } else if (typeid(int *) == typeid(Type)) {
            return "int*";
        } else if (typeid(unsigned int *) == typeid(Type)) {
            return "unsigned int*";
        } else if (typeid(unsigned long int *) == typeid(Type)) {
            return "unsigned long int*";
        } else if (typeid(unsigned long long int *) == typeid(Type)) {
            return "unsigned long long int*";
        } else if (typeid(int **) == typeid(Type)) {
            return "int**";
        } else if (typeid(unsigned int **) == typeid(Type)) {
            return "unsigned int**";
        } else if (typeid(unsigned long int **) == typeid(Type)) {
            return "unsigned long int*";
        } else if (typeid(unsigned long long int **) == typeid(Type)) {
            return "unsigned long long int**";
        } else if (typeid(float *) == typeid(Type)) {
            return "float*";
        } else if (typeid(float **) == typeid(Type)) {
            return "float**";
        } else if (typeid(double *) == typeid(Type)) {
            return "double*";
        } else if (typeid(long double *) == typeid(Type)) {
            return "long double*";
        } else if (typeid(double **) == typeid(Type)) {
            return "double**";
        } else if (typeid(long double **) == typeid(Type)) {
            return "long double**";
        } else {
            return typeid(Type).name();
        }
    }

    template<typename T>
    void printType(const std::string &text, T t) {
        std::cout << text << " " << type(t) << std::endl;
    }

    template<typename T>
    T convert(const std::string &str) {
        // Usage:
        //std::cout<<std::setprecision(30)<<convert<T>("3.141592653589793238462643383279502884197169399375105820974944")<<std::endl;
        //float -> 3.1415927410125732421875
        //double -> 3.14159265358979311599796346854
        //long double -> 3.14159265358979323851280895941

        std::istringstream ss(str);
        T x;
        ss >> x;

        return x;
    }
}
#endif // lxl_TYPES_H_
