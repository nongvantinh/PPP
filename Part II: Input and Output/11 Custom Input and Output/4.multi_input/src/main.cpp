/*
4. Write a program called multi_input.cpp that prompts the user to enter several integers in any combination of octal,
decimal, or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly; and converts them to decimal
form. Then your program should output the values in properly spaced columns like this:
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

std::vector<std::string> get_words(const std::string &list_int);
int string_to_int(const std::string &s);
void field(const std::string &, int);
std::vector<std::string> fill_vector();

int main()
{
    std::cout << "Enter value: ";
    std::vector<std::string> list_num(fill_vector());

    for (const std::string &s : list_num)
    {
        int number = string_to_int(s);
        field(s, number); // yield result.
    }
}

std::vector<std::string> get_words(const std::string &list_int)
{
    std::stringstream sss(list_int);
    std::vector<std::string> v;
    for (std::string s; sss >> s;)
        v.push_back(s);
    return v;
}

int string_to_int(const std::string &s)
{
    std::stringstream sss(s);
    sss.unsetf(std::ios::dec);
    sss.unsetf(std::ios::hex); // Ox or 0X mean hexadecimal.
    sss.unsetf(std::ios::oct); // 0 mean octal.
    int number(0);
    sss >> number;
    if (!sss)
    {
        std::string str = "can't interpreted as int. string " + s + "\n";
        throw std::runtime_error(str);
    }
    return number;
}

void field(const std::string &s, int number)
{
    if (s[0] == '0' && (char)toupper(s[1]) == 'X')
    {
        std::cout << std::setw(20) << s << std::setw(20) << "hexadecimal" << std::setw(20)
                  << "convert to" << std::setw(20) << number << std::setw(20) << "decimal\n";
        return;
    }
    else if (s[0] == '0')
    {
        std::cout << std::setw(20) << s << std::setw(20) << "octal" << std::setw(20)
                  << "convert to" << std::setw(20) << number << std::setw(20) << "decimal\n";
        return;
    }
    else
    {
        std::cout << std::setw(20) << s << std::setw(20) << "decimal" << std::setw(20)
                  << "convert to" << std::setw(20) << number << std::setw(20) << "decimal\n";
        return;
    }
}
std::vector<std::string> fill_vector()
{
    std::string line_int;
    if (std::getline(std::cin, line_int))
        return get_words(line_int);
    throw std::runtime_error("Can't fill in std::vector<std::int>.\n");
}