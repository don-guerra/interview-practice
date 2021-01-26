#ifndef CONSOLE_LOGGER_H_
#define CONSOLE_LOGGER_H_

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void printVector(std::string label, std::vector<T> vect)
{
    std::cout << label << ":";
    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << " " << vect[i];
    }
    std::cout << std::endl;
}

template <typename T>
void printResult(std::string label, T val)
{
    std::cout << label << ": " << val << std::endl;
}

#endif