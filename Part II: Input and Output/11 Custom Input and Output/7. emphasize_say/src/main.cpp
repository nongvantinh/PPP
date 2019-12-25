/*
7. Modify the program from the previous exercise so that it replaces don't with do not, can't with cannot, etc.; leaves
hyphens within words intact (so that we get “ do not use the as-if rule ”); and converts all characters to lower case.
*/
#include <iostream>
std::string emphasize(const std::string &);
int main()
{
    std::string whitespace = ".;,?-'";
    std::string data = "- don't use the as-if rule.";
    std::cout << emphasize(data) << std::endl;
    return 0;
}
std::string emphasize(const std::string &data)
{
    std::string value = data;
    for (int i(0); i < value.size(); ++i)
    {
        if (value[i] == '\'')
        {
            value.erase(i - 1, 3); // delete n't
            value.insert(i, "not ");
        }
    }
    return value;
}
