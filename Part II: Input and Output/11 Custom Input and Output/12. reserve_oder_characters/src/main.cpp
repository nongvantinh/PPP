/*
12. Reverse the order of characters in a text file. For example, asdfghjkl becomes lkjhgfdsa. Warning: There is no really
good, portable, and efficient way of reading a file backward.
*/
#include <iostream>
#include <fstream>

void reserve(const std::string &);
int main()
{
    reserve("mydata.txt");
}
void reserve(const std::string &fname)
{
    std::ifstream ifs(fname);
    if (!ifs)
        throw std::runtime_error("Can't open for reading.\n");
    std::string data, data2;
    ifs >> data;

    for (int i(data.size() - 1); 0 <= i; --i)
    {
        data2 += data[i];
    }

    
    ifs.close();
    std::ofstream ofs(fname);
    ofs << data2;
}
