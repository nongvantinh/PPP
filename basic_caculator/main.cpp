#include "../std_lib_facilities.h"

int calculate(double, char, double);
string message(double, char, double);
int main()
{
    cout << "enter expresion: ";
    double a, b, c;
    char expr{' '};
    cin >> a >> expr >> b;

    cout << message(a, expr, b) << '\n';
    return 0;
}

string message(double first, char expr, double second)
{
    ostringstream oss;
    switch (expr)
    {
    case '+':
        oss << "the sum of " << first << " and " << second << " is: " << calculate(first, expr, second);
        return oss.str();
    case '-':
        oss << "the subtract of " << first << " and " << second << " is: " << calculate(first, expr, second);
        return oss.str();
    case '*':
        oss << "the multiply of " << first << " and " << second << " is: " << calculate(first, expr, second);
        return oss.str();
    case '/':
        oss << "the divided of " << first << " and " << second << " is: " << calculate(first, expr, second);
        return oss.str();
    default:
        throw runtime_error("unexpected expr.\n");
    }
}

int calculate(double first, char expr, double second)
{
    switch (expr)
    {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '*':
        return first * second;
    case '/':
        return (second == 0) ? throw runtime_error("devided by zero.\n") : first / second;
    default:
        throw runtime_error("unexpected expr.\n");
    }
}