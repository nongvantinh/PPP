#include "../std_lib_facilities.h"

int main()
{
    // Fomular convert celsious to fahrenrit.
    cout << "Enter value in celsious or fahrenrit (c/f): " << endl;
    double value{0.0};
    char unit (' ');
    cin >> value >> unit;
    double celsious_to_fahrenrit = {9.0/5 * value + 32};
    if (unit == 'c')
    {
        cout << "value: " << value << "c == " << value / celsious_to_fahrenrit << 'f' << '\n'; 
    }
    else if (unit == 'f')
    {
        cout << "value: " << value  << "f == " << value * celsious_to_fahrenrit << 'c' << '\n'; 
    }

    return 0;

}
