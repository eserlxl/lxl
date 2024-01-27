#ifndef lxl_UTILS_FETCHDATA_H
#define lxl_UTILS_FETCHDATA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include "utils/type.h"
#include "algo.h"

namespace lxl {
    template<typename T> void detectDelimiter(const std::string &fileName,T* delimiterDetected) {

        std::vector<std::string> delimiterArray = {" ",",","\t",";","|",":","_"};
        std::vector<uzi> delimiterArrayPoints(delimiterArray.size());

        std::ifstream f;

        try {
            f.open(fileName);
        } catch (std::system_error &e) {
            std::cerr << e.code().message() << std::endl;
        }

        if (f.is_open()) {
            std::string line;
            while (getline(f, line)) {
                uzi i=0;
                for(auto &delimiter:delimiterArray)
                {
                    delimiterArrayPoints[i++]+=explode(delimiter, trim_copy(line)).size();
                }
            }
            f.close();

            *delimiterDetected = delimiterArray[max(delimiterArrayPoints)[1]];
        } else {
            throw std::system_error(errno, std::system_category(), "Failed to open " + fileName);
        }

        f.clear();
    }

    template<typename T1, typename T2>
    void fetchData(const std::string &fileName, std::vector<std::vector<T1>> &data, const T2 delimiter) {
        std::ifstream f;

        try {
            f.open(fileName);
        } catch (std::system_error &e) {
            std::cerr << e.code().message() << std::endl;
        }

        if (f.is_open()) {
            std::string line;
            while (getline(f, line)) {
                std::vector<std::string> stringData = explode(delimiter, trim_copy(line));
                std::vector<T1> tempVec;
                convert(stringData, tempVec);
                data.push_back(tempVec);
            }
            f.close();
        } else {
            throw std::system_error(errno, std::system_category(), "Failed to open " + fileName);
        }

        f.clear();
    }

    template<typename T1, typename T2>
    void fetchDataGzip(const std::string &fileName, std::vector<std::vector<T1>> &data, const T2 delimiter) {

        std::ifstream file(fileName, std::ios_base::in | std::ios_base::binary);

        if (file.is_open()) {

            boost::iostreams::filtering_streambuf<boost::iostreams::input> inbuf;
            inbuf.push(boost::iostreams::gzip_decompressor());
            inbuf.push(file);

            //Convert streambuf to istream
            std::istream instream(&inbuf);

            std::string line;
            while (getline(instream, line)) {
                std::vector<std::string> stringData = explode(delimiter, trim_copy(line));
                std::vector<T1> tempVec;
                convert(stringData, tempVec);
                data.push_back(tempVec);
            }
            boost::iostreams::close(inbuf);
            file.close();
        } else {
            throw std::system_error(errno, std::system_category(), "Failed to open " + fileName);
        }

        file.clear();
    }

    template<typename T1, typename T2>
    void fetchDataTranspose(const std::string &fileName, std::vector<std::vector<T1>> &data, const T2 delimiter) {
        std::ifstream f;

        try {
            f.open(fileName);
        } catch (std::system_error &e) {
            std::cerr << e.code().message() << std::endl;
        }

        if (f.is_open()) {
            std::string line;

            uzi lineCount = 0;
            while (getline(f, line)) {
                std::vector<std::string> stringData = explode(delimiter, trim_copy(line));

                if (lineCount == 0) {
                    std::vector<T1> tempVec;
                    for (uzi j = 0; j < stringData.size(); j++) {
                        data.push_back(tempVec);
                    }
                }
                for (uzi j = 0; j < stringData.size(); j++) {
                    data[j].push_back(convert<T1>(stringData[j]));
                }
                lineCount++;
            }
            f.close();
        } else {
            throw std::system_error(errno, std::system_category(), "Failed to open " + fileName);
        }

        f.clear();
    }

    template<typename T1, typename T2>
    void fetchDataTransposeGzip(const std::string &fileName, std::vector<std::vector<T1>> &data, const T2 delimiter) {
        std::ifstream file(fileName, std::ios_base::in | std::ios_base::binary);

        if (file.is_open()) {

            boost::iostreams::filtering_streambuf<boost::iostreams::input> inbuf;
            inbuf.push(boost::iostreams::gzip_decompressor());
            inbuf.push(file);

            //Convert streambuf to istream
            std::istream instream(&inbuf);

            std::string line;
            uzi lineCount = 0;
            while (getline(instream, line)) {
                std::vector<std::string> stringData = explode(delimiter, trim_copy(line));

                if (lineCount == 0) {
                    std::vector<T1> tempVec;
                    for (uzi j = 0; j < stringData.size(); j++) {
                        data.push_back(tempVec);
                    }
                }
                for (uzi j = 0; j < stringData.size(); j++) {
                    data[j].push_back(convert<T1>(stringData[j]));
                }
                lineCount++;
            }
            boost::iostreams::close(inbuf);
            file.close();
        } else {
            throw std::system_error(errno, std::system_category(), "Failed to open " + fileName);
        }

        file.clear();
    }
}
#endif //lxl_UTILS_FETCHDATA_H
