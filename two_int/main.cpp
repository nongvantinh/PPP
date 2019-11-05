#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter number 1: ";
    double val1{0};
    cin >> val1;

    cout << "Enter number 2: ";
    double val2{0};
    cin >> val2;

    if (val1 < val2)
        cout << val1 << " < " << val2 << '\n';
    else if (val1 > val2)
        cout << val1 << " > " << val2 << '\n';
    else
        cout << "It's same.\n";

    cout << "There sum is: " << val1 + val2 << '\n';
    cout << "There difference is: " << val1 / val2 << '\n';
    cout << "There product is: " << val1 * val2 << '\n';
    cout << "There  ratio is: "
         << "number 1: " << (val1 / 10) << " number 2: " << (val2 / 10) << '\n';
}