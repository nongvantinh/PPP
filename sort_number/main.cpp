#include "../std_lib_facilities.h"


void sort_number();
void sort_string();
int main()
{
    sort_string();
}

void sort_number()
{

    int a, b, c;
    a = b = c = 0;

    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    if (a < b)
    {
        if (a < c)
        {
            if (b < c)
                cout << a << '\t' << b << '\t' << c << '\n';
            else
                cout << a << '\t' << c << '\t' << b << '\n';
        }
        else // a > c then c is smalest.
        {
            cout << c << '\t' << a << '\t' << b << '\n';
        }
    }
    else if (b < c)
    {
        // Is b < a?
        if (b < a)
        {
            if (a < c)
                cout << b << '\t' << a << '\t' << c << '\n';
            else
                cout << b << '\t' << c << '\t' << a << '\n';
        }
        else
            cout << a << '\t' << b << '\t' << c << '\n';
    }
    else if (c < a)
    {
        if (c < b)
        {
            if (a < b)
                cout << c << '\t' << a << '\t' << b << '\n';
            else
                cout << c << '\t' << b << '\t' << a << '\n';
        }
        else
            cout << c << '\t' << b << '\t' << a << '\n';
    }
}

void sort_string()
{

    string a, b, c;

    cout << "Enter three strings: ";
    cin >> a >> b >> c;
    if (a < b)
    {
        if (a < c)
        {
            if (b < c)
                cout << a << '\t' << b << '\t' << c << '\n';
            else
                cout << a << '\t' << c << '\t' << b << '\n';
        }
        else // a > c then c is smalest.
        {
            cout << c << '\t' << a << '\t' << b << '\n';
        }
    }
    else if (b < c)
    {
        // Is b < a?
        if (b < a)
        {
            if (a < c)
                cout << b << '\t' << a << '\t' << c << '\n';
            else
                cout << b << '\t' << c << '\t' << a << '\n';
        }
        else
            cout << a << '\t' << b << '\t' << c << '\n';
    }
    else if (c < a)
    {
        if (c < b)
        {
            if (a < b)
                cout << c << '\t' << a << '\t' << b << '\n';
            else
                cout << c << '\t' << b << '\t' << a << '\n';
        }
        else
            cout << c << '\t' << b << '\t' << a << '\n';
    }
}