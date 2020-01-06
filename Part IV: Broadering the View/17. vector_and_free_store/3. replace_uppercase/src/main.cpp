#include <iostream>

void to_lower(char *s);
bool is_upper(char c);
int main()
{
    char s[] = "Hello, World!\0";
    to_lower(s);
    std::cout << s << std::endl;
    return 0;
}
bool is_upper(char c)
{
    return 65 <= c && c <= 90;
}

void to_lower(char *s)
{
    for (int i(0); s[i] != 0; ++i)
        if (is_upper(s[i]))
            s[i] = char(s[i] + 32);
}
