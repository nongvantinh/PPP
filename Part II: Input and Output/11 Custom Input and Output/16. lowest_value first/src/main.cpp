/*
16. Write a program to read a file of whitespace-separated numbers and output them in order (lowest value first), one value
per line. Write a value only once, and if it occurs more than once write the count of its occurrences on its line. For
example, 7 5 5 7 3 117 5 should give.
3
5 3
7 2
117
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <map>

// #include "../../../std_lib_facilities.h"
int main()
{
    std::ifstream ifs("mydata.txt");
    std::ofstream ofs("newdata.txt");
    if (!ifs)
        throw std::runtime_error("can't open file to read data.\n");
    if (!ofs)
        throw std::runtime_error("can't open file to write data.\n");

    std::map<int, int> dat;
    for (int number(0); ifs >> number;)
    {

        try
        {
            ++dat.at(number);
        }
        catch (std::exception &ex)
        {
            ++dat[number];
        }
    }
    for (auto &x : dat)
        if (x.second == 1) // It happen just one.
            ofs << x.first << std::endl;
        else
            ofs << x.first << ' ' << x.second << std::endl;
}