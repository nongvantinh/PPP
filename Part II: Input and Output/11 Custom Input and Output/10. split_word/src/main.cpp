/*
10. Write a function vector<string> split(const string& s) that returns a vector of whitespace-separated substrings
from the argument s.
*/
#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> split(const std::string &);
int main()
{

    std::cout << "Hello Easy C++ project!" << std::endl;
}
std::vector<std::string> split(const std::string &s)
{
    if(s.size == 0)
    throw std::runtime_error("s have invalid size that is s <=0.\n");
    std::vector<std::string> v;
    std::stringstream sss(s);
    std::string word;
    if (sss >> word)
        v.push_back(word);
    return v;
}
