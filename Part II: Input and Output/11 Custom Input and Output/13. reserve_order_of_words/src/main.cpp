/*
13. Reverse the order of words (defined as whitespace-separated strings) in a file. For example, Norwegian Blue parrot
becomes parrot Blue Norwegian. You are allowed to assume that all the strings from the file will fit into memory at
once.
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
    std::ofstream ofs("new" + fname);

    while (ifs >> data)
    {
        ofs.seekp(0);
        ofs << data << ' ';
    }

    ifs.close();
    ofs.close();
}
