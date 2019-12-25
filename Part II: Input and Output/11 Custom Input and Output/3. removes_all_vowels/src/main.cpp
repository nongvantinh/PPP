/*
3. Write a program that removes all vowels from a file (“disemvowels”). For example, Once upon a time! becomes nc
pn tm!. Surprisingly often, the result is still readable; try it on your friends.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

std::string get_data(const std::string &);
bool is_vowels(char ch);
int main()
{
    std::string data = get_data("mydata.txt");
    std::cout << data << std::endl;
    std::ofstream ofs("newdata.txt");
    ofs << data;
    return 0;
}
bool is_vowels(char ch)
{
    std::string vowels{"ueoai"};
    for (char c : vowels)
        if ((char)toupper(ch) == (char)toupper(c))
            return true;
    return false;
}

std::string get_data(const std::string &fname)
{
    std::ifstream ifs(fname);
    if (!ifs)
        throw std::runtime_error("Can't open file for reading.");
    std::string line;
    std::getline(ifs, line);
    for (int i(0); i < line.size(); ++i)
    {
        if (is_vowels(line[i]))
            line.erase(i, 1);
    }
    ifs.close();
    return line;
}
