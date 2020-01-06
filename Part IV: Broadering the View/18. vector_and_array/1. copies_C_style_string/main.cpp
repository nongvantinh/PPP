/*
1. Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store. Do
not use any standard library functions. Do not use subscripting; use the dereference operator * instead.
*/
#include <iostream>
#define DEBUG(x) std::cout << '>' << #x << ':' << x << std::endl;
char *strdup(const char *);
int strlen(const char *);
int main()
{
    char *source = "hello world";
    char *mystr = strdup(source);
    DEBUG(mystr);
    delete[] mystr;
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

char *strdup(const char *c)
{
    int length = strlen(c);
    char *p = new char[length];

    while (*c)
    {
        *p = *c;
        ++p;
        ++c;
    }
    p -= length;
    return p;
}
