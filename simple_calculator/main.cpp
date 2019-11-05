#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter operation follow with 2 operands: ";
    char oper{' '};
    double operand1, operand2;
    operand1 = operand2;
    cin >> oper >> operand1 >> operand2;

    if (oper == '+')
        cout << operand1 << '+' << operand2 << '=' << operand1 + operand2 << '\n';
    else if (oper == '-')
        cout << operand1 << '-' << operand2 << '=' << operand1 - operand2 << '\n';
    else if (oper == '*')
        cout << operand1 << '*' << operand2 << '=' << operand1 * operand2 << '\n';
    else if (oper == '/')
        cout << operand1 << '/' << operand2 << '=' << operand1 / operand2 << '\n';
    else
        cout << "I don't know this operation.\n";
    return 0;
}