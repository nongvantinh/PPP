#include <iostream>

char *findx(const char *, const char *x);
int main()
{
    char *s = new char[10];
    scanf("%s", &s);
    std::cout << s << std::endl;
    return 0;
}

char *findx(const char *s, const char *x)
{
    for (int i(0); s[i] != 0; ++i)
        if (s[i] == *x)
            return new char(*x);
    throw std::runtime_error("x not found.\n");
}
