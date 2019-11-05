#include "../std_lib_facilities.h"

int main()
{
    string number;
    cout << "Let spell out some numbers: ";
    cin >> number;
    if (number == "one")
        cout << 1 << '\n';
    else if (number == "two")
        cout << 2 << '\n';
    else if (number == "three")
        cout << 3 << '\n';
    else if (number == "four")
        cout << 4 << '\n';
    else
        cout << "Sorry that is not the number i know.\n";

    return 0;
}