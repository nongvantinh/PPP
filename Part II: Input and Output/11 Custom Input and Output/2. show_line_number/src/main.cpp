/*
2. Write a program that given a file name and a word outputs each line that contains that word together with the line
number. Hint: getline().
*/
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs("mydata.txt");
    if (!ifs)
        throw std::runtime_error("Can't open file for read.\n");
    

}