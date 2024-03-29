#ifndef lxl_TYPES_H_
#define lxl_TYPES_H_

#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <sstream>

namespace lxl {
    typedef std::size_t uzi;

    typedef std::vector<std::string> matrixString1D;
    typedef std::vector<matrixString1D> matrixString2D;
    typedef std::vector<matrixString2D> matrixString3D;
    typedef std::vector<matrixString3D> matrixString4D;
    typedef std::vector<matrixString4D> matrixString5D;
    typedef std::vector<matrixString5D> matrixString6D;

    typedef std::vector<uzi> matrixUzi1D;
    typedef std::vector<matrixUzi1D> matrixUzi2D;
    typedef std::vector<matrixUzi2D> matrixUzi3D;
    typedef std::vector<matrixUzi3D> matrixUzi4D;
    typedef std::vector<matrixUzi4D> matrixUzi5D;
    typedef std::vector<matrixUzi5D> matrixUzi6D;

    typedef std::vector<int> matrixInt1D;
    typedef std::vector<matrixInt1D> matrixInt2D;
    typedef std::vector<matrixInt2D> matrixInt3D;
    typedef std::vector<matrixInt3D> matrixInt4D;
    typedef std::vector<matrixInt4D> matrixInt5D;
    typedef std::vector<matrixInt5D> matrixInt6D;

    typedef std::vector<float> matrixFloat1D;
    typedef std::vector<matrixFloat1D> matrixFloat2D;
    typedef std::vector<matrixFloat2D> matrixFloat3D;
    typedef std::vector<matrixFloat3D> matrixFloat4D;
    typedef std::vector<matrixFloat4D> matrixFloat5D;
    typedef std::vector<matrixFloat5D> matrixFloat6D;

    typedef std::vector<double> matrixDouble1D;
    typedef std::vector<matrixDouble1D> matrixDouble2D;
    typedef std::vector<matrixDouble2D> matrixDouble3D;
    typedef std::vector<matrixDouble3D> matrixDouble4D;
    typedef std::vector<matrixDouble4D> matrixDouble5D;
    typedef std::vector<matrixDouble5D> matrixDouble6D;

    typedef std::vector<long double> matrixLongDouble1D;
    typedef std::vector<matrixLongDouble1D> matrixLongDouble2D;
    typedef std::vector<matrixLongDouble2D> matrixLongDouble3D;
    typedef std::vector<matrixLongDouble3D> matrixLongDouble4D;
    typedef std::vector<matrixLongDouble4D> matrixLongDouble5D;
    typedef std::vector<matrixLongDouble5D> matrixLongDouble6D;

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
