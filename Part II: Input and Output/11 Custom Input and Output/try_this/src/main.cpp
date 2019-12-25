#include <iostream>
#include <iomanip>
void show_base();
void floating_point_ouput();
void fields();
int main()
{
    fields();
}

void fields()
{
    int a(123456);
    std::cout << a
              << "|" << std::setw(4) << a << "|"
              << std::setw(8) << a << "|"
              << a << "|\n";
}
void floating_point_ouput()
{
    double a(1234567.89);
    std::cout << std::defaultfloat << a << "\t\t(defaultfloat)\n"
              << std::fixed << a << "\t(fixed)\n"
              << std::scientific << a << "\t(sientific)\n";
}
void show_base()
{
    int a(1234), b(0x4d2), c(02322), d(02322);
    std::cout << std::showbase << std::dec;
    std::cout << a << "\t(decimal)\n"
              << b << "\t(hexadecimal)\n"
              << c << "\t(octal)\n"
              << d << "\t(octal)\n";
}