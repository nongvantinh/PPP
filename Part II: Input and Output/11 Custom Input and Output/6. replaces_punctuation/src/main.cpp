/*
6. Write a program that replaces punctuation with whitespace. Consider . (dot), ; (semicolon), , (comma), ? (question
mark), - (dash), ' (single quote) punctuation characters. Don’t modify characters within a pair of double quotes ("). For
example, “- don't use the as-if rule.” becomes “ don t use the as if rule ”.
*/
#include <iostream>
std::string to_whitespace(const std::string &);
int main()
{
    std::string whitespace = ".;,?-'";
    std::string data = "- don't use the as-if rule.";
    std::cout << to_whitespace(data) << std::endl;
    return 0;
}
std::string to_whitespace(const std::string &data)
{
    std::string value = data;
    for (char &ch : value)
    {
        switch (ch)
        {
        case '.':
        case ';':
        case ',':
        case '?':
        case '-':
        case '\'':
            ch = ' ';
            break;

        default:
            break;
        }
    }
    return value;
}
