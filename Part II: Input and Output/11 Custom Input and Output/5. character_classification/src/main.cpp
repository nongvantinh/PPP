/*
5. Write a program that reads strings and for each string outputs the character classification of each character, as defined by
the character classification functions presented in §11.6. Note that a character can have several classifications (e.g., x is
both a letter and an alphanumeric).
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

std::vector<std::string> get_strings(const std::string &);
void character_classification(const std::string &);
std::string classification(char);

int main()
{

    std::vector<std::string> list_strings = get_strings("mydata.txt");
    for (const std::string &str : list_strings)
        character_classification(str);
    return 0;
}
std::string classification(char ch)
{
    std::ostringstream oss;
    if (isspace(ch))
    {
        oss << ch << " is space\n";
    }
    else if (isalpha(ch))
    {
        oss <<ch <<  " is alpha";
        if (isupper(ch))
        {
            oss << " and is upper";
        }
        else if (islower(ch))
        {
            oss << " and is lower";
        }
        if (isxdigit(ch))
        {
            oss << " and is hexadecimal digit";
        }
        oss << '\n';
    }
    else if (isdigit(ch))
    {
        oss << ch << " is decimal digit\n";
    }
    else if (iscntrl(ch))
    {
        oss << ch << " is control\n";
    }
    else if (isprint(ch))
    {
        oss << ch << " is printable\n";
    }
    return oss.str();
}

void character_classification(const std::string &line)
{
    for (const char &ch : line)
    {
        std::cout << classification(ch);
    }
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
