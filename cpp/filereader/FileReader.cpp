#include "../../headers/filereader/FileReader.hpp"

void FileReader::storeval(int val, const std::string &filename)
{
    std::ofstream file(filename);

    if (file.is_open()) 
    {
        file << val;
        file.close();
    }
};

int FileReader::loadval(const std::string &filename)
{
    std::ifstream file(filename);

    int val;
    if (file.is_open())
    {
        
        file >> val;
        file.close();

        return val;
    }

    return val;
};

void FileReader::storearray(chtype** arr, int rows, int cols, const std::string& filename)
{
    std::ofstream file(filename);

    if (file.is_open())
    {
        file << rows << " " << cols << std::endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                file << arr[i][j] << " ";
            }
            file << std::endl;
        }

        file.close();
    }
};

chtype** FileReader::loadarray(const std::string& filename, int& rows, int& cols)
{
    chtype** arr = nullptr;
    std::ifstream file(filename);

    if (file.is_open())
    {
        file >> rows >> cols;

        arr = new chtype*[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new chtype[cols];
            for (int j = 0; j < cols; j++)
            {
                file >> arr[i][j];
            }
        }

        file.close();
    }

    return arr;
};

void FileReader::freearray(chtype** arr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
};