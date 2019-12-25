//1. Write a program that reads a text file and converts its input to all lower case, producing a new file.
#include <iostream>
#include <fstream>
#include <iomanip>

void all_to_lower(const std::string &);
int main()
{
    std::string fname("myData.txt");
    all_to_lower(fname);
    return 0;
}
void all_to_lower(const std::string &fname)
{
    std::ifstream ifs(fname);
    if (!ifs)
        throw std::runtime_error("open file to read failed!\n");
    std::string line;
    std::ofstream ofs("newData.txt");
    if (!ofs)
        throw std::runtime_error("open file to write failed!\n");
    ofs.close();
    while (ifs)
    {
        ofs.open("newData.txt", std::ios_base::app);
        if (!ofs)
            throw std::runtime_error("open file to write failed!\n");
        std::getline(ifs, line);
        for (char &ch : line)
        {
            if (isalpha(ch))
                ch = tolower(ch);
        }
        ofs << line << std::endl;
        ofs.close();
    }
}
