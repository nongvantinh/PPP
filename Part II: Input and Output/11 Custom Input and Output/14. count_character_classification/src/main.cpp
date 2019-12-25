/*
14. Write a program that reads a text file and writes out how many characters of each character classification (§11.6) are in
the file.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

struct CountClassification
{
    uint32_t space{0};
    uint32_t alpha{0};
    uint32_t upper{0};
    uint32_t lower{0};
    uint32_t digit{0};
    uint32_t xdigit{0};
    uint32_t cntrl{0};
    uint32_t printable{0};
    CountClassification operator+=(const CountClassification &c)
    {
        space += c.space;
        alpha += c.alpha;
        upper += c.upper;
        lower += c.lower;
        digit += c.digit;
        xdigit += c.xdigit;
        cntrl += c.cntrl;
        printable += c.printable;
    }
};

std::vector<std::string> get_strings(const std::string &);
CountClassification character_classification(const std::string &);
CountClassification classification(char);

int main()
{

    std::vector<std::string> list_strings = get_strings("mydata.txt");
    CountClassification count;
    for (const std::string &str : list_strings)
        count += character_classification(str);

    std::cout << "alpha: " << count.alpha << std::endl;
    std::cout << "cntl: " << count.cntrl << std::endl;
    std::cout << "digit: " << count.digit << std::endl;
    std::cout << "lower: " << count.lower << std::endl;
    std::cout << "printable: " << count.printable << std::endl;
    std::cout << "space: " << count.space << std::endl;
    std::cout << "upper: " << count.upper << std::endl;
    std::cout << "xdigit: " << count.xdigit << std::endl;
    return 0;
}
CountClassification classification(char ch)
{
    CountClassification count;
    if (isspace(ch))
    {
        ++count.space;
    }
    else if (isalpha(ch))
    {
        ++count.alpha;
        if (isupper(ch))
        {
            ++count.upper;
        }
        else if (islower(ch))
        {
            ++count.lower;
        }
        if (isxdigit(ch))
        {
            ++count.xdigit;
        }
    }
    else if (isdigit(ch))
    {
        ++count.digit;
    }
    else if (iscntrl(ch))
    {
        ++count.cntrl;
    }
    else if (isprint(ch))
    {
        ++count.printable;
    }
    return count;
}

CountClassification character_classification(const std::string &line)
{
    CountClassification count;
    for (const char &ch : line)
    {
        count += classification(ch);
    }
    return count;
}

std::vector<std::string> get_strings(const std::string &fname)
{
    std::ifstream ifs(fname);
    if (!ifs)
        throw std::runtime_error("Can't open file for reading.\n");
    std::vector<std::string> list_strings;
    while (ifs)
    {
        std::string line;
        std::getline(ifs, line);
        list_strings.push_back(line);
    }

    return list_strings;
}
