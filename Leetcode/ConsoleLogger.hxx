#ifndef CONSOLE_LOGGER_H_
#define CONSOLE_LOGGER_H_

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void printVector(std::string label, std::vector<T> &vect)
{
    std::cout << label << ":";
    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << " " << vect[i];
    }
    std::cout << std::endl;
}

template <typename T>
void print2D(std::string label, std::vector<std::vector<T>> &vect_2d)
{
    std::cout << label << "\n";
    for (int i = 0; i < vect_2d.size(); i++)
    {
        for (int j = 0; j < vect_2d[0].size(); j++)
        {
            std::cout << vect_2d[i][j] << "\t";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

template <typename T>
void printResult(std::string label, T val)
{
    std::cout << label << ": " << val << std::endl;
}

#endif