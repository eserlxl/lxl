#ifndef lxl_GZIP_H_
#define lxl_GZIP_H_

#include <vector>
#include <fstream>
#include <sstream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>

// Derived from yfnick's Gzip class. https://gist.github.com/yfnick/6ba33efa7ba12e93b148
namespace lxl {
    class Gzip {
    public:
        static std::string compress(const std::string &data) {
            std::stringstream compressed;
            std::stringstream origin(data);

            boost::iostreams::filtering_streambuf<boost::iostreams::input> out;
            out.push(boost::iostreams::gzip_compressor(
                    boost::iostreams::gzip_params(boost::iostreams::gzip::best_compression)));
            out.push(origin);
            boost::iostreams::copy(out, compressed);

            return compressed.str();
        }

        static std::string decompress(const std::string &data) {
            std::stringstream compressed(data);
            std::stringstream decompressed;

            boost::iostreams::filtering_streambuf<boost::iostreams::input> out;
            out.push(boost::iostreams::gzip_decompressor());
            out.push(compressed);
            boost::iostreams::copy(out, decompressed);

            return decompressed.str();
        }

        static void compress(const std::string &sourceFileName, const std::string &targetFileName) {

            std::ifstream inStream(sourceFileName, std::ios_base::in | std::ios_base::binary);
            std::ofstream outStream(targetFileName, std::ios_base::out | std::ios_base::binary);

            boost::iostreams::filtering_streambuf<boost::iostreams::output> outbuf;
            outbuf.push(boost::iostreams::gzip_compressor(
                    boost::iostreams::gzip_params(boost::iostreams::gzip::best_compression)));
            outbuf.push(outStream);

            //Convert streambuf to ostream
            std::ostream out(&outbuf);

            /*Read data using streambuffer iterators.*/
            std::vector<char> buf((std::istreambuf_iterator<char>(inStream)), (std::istreambuf_iterator<char>()));

            /*str_buf holds all the data including whitespaces and newline .*/
            std::string str_buf(buf.begin(), buf.end());

            out << str_buf;

            //Cleanup
            boost::iostreams::close(outbuf);

            inStream.close();
            outStream.close();
        }

        static void decompress(const std::string &sourceFileName, const std::string &targetFileName) {

            std::ifstream inStream(sourceFileName, std::ios_base::in | std::ios_base::binary);
            std::ofstream outStream(targetFileName, std::ios_base::out | std::ios_base::binary);

            boost::iostreams::filtering_streambuf<boost::iostreams::output> outbuf;
            outbuf.push(boost::iostreams::gzip_decompressor());
            outbuf.push(outStream);

            //Convert streambuf to ostream
            std::ostream out(&outbuf);

            /*Read data using streambuffer iterators.*/
            std::vector<char> buf((std::istreambuf_iterator<char>(inStream)), (std::istreambuf_iterator<char>()));

            /*str_buf holds all the data including whitespaces and newline .*/
            std::string str_buf(buf.begin(), buf.end());

            out << str_buf;

            //Cleanup
            boost::iostreams::close(outbuf);

            inStream.close();
            outStream.close();
        }

        static void compress(std::ifstream &inStream, const std::string &targetFileName) {

            std::ofstream outStream(targetFileName, std::ios_base::out | std::ios_base::binary);

            boost::iostreams::filtering_streambuf<boost::iostreams::output> outbuf;
            outbuf.push(boost::iostreams::gzip_compressor(
                    boost::iostreams::gzip_params(boost::iostreams::gzip::best_compression)));
            outbuf.push(outStream);

            //Convert streambuf to ostream
            std::ostream out(&outbuf);

            /*Read data using streambuffer iterators.*/
            std::vector<char> buf((std::istreambuf_iterator<char>(inStream)), (std::istreambuf_iterator<char>()));

            /*str_buf holds all the data including whitespaces and newline .*/
            std::string str_buf(buf.begin(), buf.end());

            out << str_buf;

            //Cleanup
            boost::iostreams::close(outbuf);

            inStream.close();
            outStream.close();
        }

        static void compress(std::istream &inStream, const std::string &targetFileName) {

            std::ofstream outStream(targetFileName, std::ios_base::out | std::ios_base::binary);

            boost::iostreams::filtering_streambuf<boost::iostreams::output> outbuf;
            outbuf.push(boost::iostreams::gzip_compressor(
                    boost::iostreams::gzip_params(boost::iostreams::gzip::best_compression)));
            outbuf.push(outStream);

            //Convert streambuf to ostream
            std::ostream out(&outbuf);

            /*Read data using streambuffer iterators.*/
            std::vector<char> buf((std::istreambuf_iterator<char>(inStream)), (std::istreambuf_iterator<char>()));

            /*str_buf holds all the data including whitespaces and newline .*/
            std::string str_buf(buf.begin(), buf.end());

            out << str_buf;

            //Cleanup
            boost::iostreams::close(outbuf);

            outStream.close();
        }

        static void compress(std::stringstream &inStream, const std::string &targetFileName) {

            std::ofstream outStream(targetFileName, std::ios_base::out | std::ios_base::binary);

            boost::iostreams::filtering_streambuf<boost::iostreams::output> outbuf;
            outbuf.push(boost::iostreams::gzip_compressor(
                    boost::iostreams::gzip_params(boost::iostreams::gzip::best_compression)));
            outbuf.push(outStream);

            //Convert streambuf to ostream
            std::ostream out(&outbuf);

            /*Read data using streambuffer iterators.*/
            std::vector<char> buf((std::istreambuf_iterator<char>(inStream)), (std::istreambuf_iterator<char>()));

            /*str_buf holds all the data including whitespaces and newline .*/
            std::string str_buf(buf.begin(), buf.end());

            out << str_buf;

            //Cleanup
            boost::iostreams::close(outbuf);

            outStream.close();
        }

        static void compress(std::string &data, const std::string &targetFileName) {

            std::ofstream outStream(targetFileName, std::ios_base::out | std::ios_base::binary);

            boost::iostreams::filtering_streambuf<boost::iostreams::output> outbuf;
            outbuf.push(boost::iostreams::gzip_compressor(
                    boost::iostreams::gzip_params(boost::iostreams::gzip::best_compression)));
            outbuf.push(outStream);

            //Convert streambuf to ostream
            std::ostream out(&outbuf);

            out << data;

            //Cleanup
            boost::iostreams::close(outbuf);

            outStream.close();
        }

        static void decompress(std::string &data, const std::string &targetFileName) {

            std::ofstream outStream(targetFileName, std::ios_base::out | std::ios_base::binary);

            boost::iostreams::filtering_streambuf<boost::iostreams::output> outbuf;
            outbuf.push(boost::iostreams::gzip_compressor(
                    boost::iostreams::gzip_params(boost::iostreams::gzip::best_compression)));
            outbuf.push(outStream);

            //Convert streambuf to ostream
            std::ostream out(&outbuf);

            out << data;

            //Cleanup
            boost::iostreams::close(outbuf);

            outStream.close();
        }

        static void compress(std::ifstream &inStream, std::ofstream &outStream) {

            boost::iostreams::filtering_streambuf<boost::iostreams::output> outbuf;
            outbuf.push(boost::iostreams::gzip_compressor(
                    boost::iostreams::gzip_params(boost::iostreams::gzip::best_compression)));
            outbuf.push(outStream);

            //Convert streambuf to ostream
            std::ostream out(&outbuf);

            /*Read data using streambuffer iterators.*/
            std::vector<char> buf((std::istreambuf_iterator<char>(inStream)), (std::istreambuf_iterator<char>()));

            /*str_buf holds all the data including whitespaces and newline .*/
            std::string str_buf(buf.begin(), buf.end());

            out << str_buf;

            //Cleanup
            boost::iostreams::close(outbuf);

            inStream.close();
            outStream.close();
        }

        static void compress(std::istream &inStream, std::ostream &outStream) {

            boost::iostreams::filtering_streambuf<boost::iostreams::output> outbuf;
            outbuf.push(boost::iostreams::gzip_compressor(
                    boost::iostreams::gzip_params(boost::iostreams::gzip::best_compression)));
            outbuf.push(outStream);

            //Convert streambuf to ostream
            std::ostream out(&outbuf);

            /*Read data using streambuffer iterators.*/
            std::vector<char> buf((std::istreambuf_iterator<char>(inStream)), (std::istreambuf_iterator<char>()));

            /*str_buf holds all the data including whitespaces and newline .*/
            std::string str_buf(buf.begin(), buf.end());

            out << str_buf;

            //Cleanup
            boost::iostreams::close(outbuf);
        }
    };
}
#endif // lxl_GZIP_H_