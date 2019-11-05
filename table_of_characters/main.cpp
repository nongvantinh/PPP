#include "../std_lib_facilities.h"

void read_and_print();
void print_characters();
void value_get_so_far();

int main()
{
    value_get_so_far();
    return 0;
}

void print_characters()
{
    for (int i{65}; i <= 122; ++i)
    {
        if (i == 'Z' + 1)
            i = 97;
        cout << char(i) << '\t' << i << '\n';
    }
}
void value_get_so_far()
{
    double value{0.0};
    double a, b; // the bigger is a and the smaller is b.
    string unit;
    double m_to_cm{100};
    double in_to_cm{2.54};
    double ft_to_in{12;
    while (cin >> value >> unit)
    {

        cout << "the value is: " << value << unit << '\n';
        if (a <= value)
        {
            a = value;
            cout << "the largest so far: " << a << '\n';
        }
        else
        {
            b = value;
            cout << "the smallest so far: " << b << '\n';
        }
    }
}

void read_and_print()
{
    while (cin)
    {
        cout << "Enter 2 numbers: ";
        double a(0);
        double b{0};
        cin >> a >> b;
        if (a < b)
            cout << "The smaller value is: " << a << "\tThe lagger value is: " << b << '\n';
        else if (a == b)
            cout << "Two numbers are equal\n";
        else
            cout << "The smaller value is: " << b << "\tThe lagger value is: " << a << '\n';
        if (abs(double(a - b)) < (1.0 / 100))
            cout << "the value are almost equal.\n";
    }
}