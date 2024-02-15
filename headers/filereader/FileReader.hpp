#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include "../../constants.hpp"
#include <string>
#include <fstream>

class FileReader
{
    public:

        static void storeval(int val, const std::string &filename);
        static int loadval(const std::string &filename);

        static void storearray(chtype** arr, int rows, int cols, const std::string& filename);
        static chtype** loadarray(const std::string& filename, int& rows, int& cols);

        static void freearray(chtype** arr, int rows);
};

#endif