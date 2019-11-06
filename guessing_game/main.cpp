// This program work doesn't quite right.
#include "../std_lib_facilities.h"

int guessing(int, int);
int check_corner(int min, int max);
int main()
{
    cout << "your number is: " << guessing(0, 100) << '\n';
    return 0;
}

int check_corner(int min, int max)
{
    cout << (min + max) / 2 << " is the number you are thinking? "
         << "?(y/n)\n";
    char corner{' '};
    cin >> corner;
    switch (corner)
    {
    case 'y':
        return (min + max) / 2;
    case 'n':
        return (min + max) / 2 + 1;
    default:
        cout << "oops you give wrong answer.\n";
        return check_corner(min, max);
    }
}

int guessing(int min, int max)
{
    if (max - min == 3)
        return check_corner(min, max);

    // cout << "Your number is between[" << min << ':' << max << ']' << " but what are your number?\n";
    cout << "Is the number you are thinking less than " << (min + max) / 2 << "?(y/n)\n";
    char answer{' '};
    cin >> answer;
    switch (answer)
    {
    case 'y':
        return guessing(min, (min + max + 2) / 2);
    case 'n':
        return guessing((min + max - 2) / 2, max);
    default:
        cout << "oops! unexpected token!Please try again\n";
        return guessing(min, max);
    }
}