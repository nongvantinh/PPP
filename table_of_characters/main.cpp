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
    double ft_to_in{12};
    while (cin >> value >> unit)
    {
        vector<double> list_value;
        list_value.push_back(value);

        double sum_in_meters(0.0);

        if (unit == "cm")
        {
            sum_in_meters += value * m_to_cm;
        }
        else if (unit == "in")
        {
            sum_in_meters += (value * in_to_cm) / m_to_cm;
        }
        else if (unit == "ft")
        {
            sum_in_meters += ((value * ft_to_in) * in_to_cm) / m_to_cm;
        }
        else if (unit == "m")
        {
            sum_in_meters += value;
        }
        else
        {
            cout << "You've entered wrong type.\n";
        }

        if (a <= sum_in_meters)
            a = sum_in_meters;
        else
            b = sum_in_meters;
        sort(list_value);
        cout << "the smallest: " << b << '\n';
        cout << "the largest: " << a << '\n';
        cout << "the number of value is: " << list_value.size() << '\n';
        double sum{0.0};
        for (double &i : list_value)
            sum += i;
        cout << "the sum of value is: " << sum << '\n';
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