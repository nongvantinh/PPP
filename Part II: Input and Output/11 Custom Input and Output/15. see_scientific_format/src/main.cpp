/*
15. Write a program that reads a file of whitespace-separated numbers and outputs a file of numbers using scientific format
and precision 8 in four fields of 20 characters per line.
*/
#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::ifstream ifs("mydata.txt");
    std::ofstream ofs("newdata.txt");
    if (!ifs)
        throw std::runtime_error("can't open file to read data.\n");
    if (!ofs)
        throw std::runtime_error("can't open file to write data.\n");
    int count(0);
    for (double number(0); ifs >> number;)
    {
        ofs << std::scientific << std::setprecision(8) << number << ' ';
        ++count;
        if (count == 20)
            ofs << std::endl;
    }
}