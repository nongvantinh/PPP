// Convert from iches to centimeters or via versa.
// a suffix 'i' or 'c'  indicates the unit of the input.
// any other suffix is an error.
#include "../std_lib_facilities.h"

int main()
{
    constexpr double cm_per_inch = 2.54;
    double length{1.0};
    char unit{' '};
    cout << "Please enter a lengtrh followed by a unit(c or i ): ";
    cin >> length >> unit;

    if (unit == 'i')
    {
        cout << length << "in == " << cm_per_inch * length << " cm\n";
    }
    else if (unit == 'c')
    {
        cout << length << "cm == " << length / cm_per_inch << " in\n";
    }
    else 
    {
        cout << "Sorry, i don't know a unit called" << unit << '\n';
    }

    return 0;
}