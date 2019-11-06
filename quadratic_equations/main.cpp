#include "../std_lib_facilities.h"
void print_solution(double, double, double);
int main()
{
    cout << "Enter a b c: ";
    double a, b, c;
    cin >> a >> b >> c;
    if (!a)
        error("equation is linear, not equadratic.\n");
    print_solution(a, b, c);
    return 0;
}

void print_solution(double a, double b, double c)
{
    double delta{b * b - (4 * a * c)};
    if (delta < 0)
        cout << "equation not have solution.\n";
    else if (!delta)
        cout << "x1 = x2 = " << (-b / 2 * a) << '\n';
    else
    {
        cout << "x1: " << ((-b) + sqrt(delta)) / (2 * a) << '\n';
        cout << "x2: " << ((-b) - sqrt(delta)) / (2 * a) << '\n';
    }
}