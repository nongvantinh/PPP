#include <iostream>
#include "../../../std_lib_facilities.h"
void print_year(int);
void print_many_base();
void print_diff();
int main()
{
    double a(1234567.89);
    std::cout << std::defaultfloat << a << "\t(defaultfloat).\n"
              << std::fixed << a << "\t(fixed).\n"
              << std::scientific << a << "\t(scientific).\n";
}
void print_year(int data)
{
    std::cout << std::showbase;
    std::cout << std::dec << data << "\t(decimal).\n"
              << std::hex << data << "\t(hexadecimal).\n"
              << std::oct << data << "\t(hexadecimal).\n"
              << std::dec;
}
void print_diff()
{
    double a(1234567.89);
    std::cout << std::defaultfloat << a << "\t(defaultfloat).\n"
              << std::fixed << a << "\t(fixed).\n"
              << std::scientific << a << "\t(scientific).\n";
}

void print_many_base()
{
    int a, b, c, d;
    std::cin >> std::dec >> a >> std::hex >> b >> std::oct >> c >> d;
    std::cout << a << '\t' << a << '\t' << c << '\t' << d << std::endl;
}
