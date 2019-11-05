#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter  integer numbe: ";
    int a{0};
    cin >> a;
    if (a % 2)
        cout << "The value: " << a << " is odd.\n";
    else
        cout << "The value: " << a << " is even.\n";
    return 0;
}