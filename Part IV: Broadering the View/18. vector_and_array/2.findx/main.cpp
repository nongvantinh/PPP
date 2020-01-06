/*
2. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in
s. Do not use any standard library functions. Do not use subscripting; use the dereference operator * instead.
*/
#include <iostream>
#define DEBUG(x) std::cout << '>' << #x << ':' << x << std::endl;
char *findx(const char *s, const char *x);
int strlen(const char *);
int main()
{
    char *source = "hello world";
    return 0;
}
int strlen(const char *p)
{
    int count(0);
    while (*p)
    {
        ++count;
        ++p;
    }
    return count;
}
char *findx(const char *s, const char *x)
{
    int length = strlen(s);
    char *p = new char[length];

    while (*s)
    {
        *p = *s;
        ++p;
        ++s;
    }
    p -= length;
    return p;
}
