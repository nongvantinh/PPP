#include "../std_lib_facilities.h"

void print_number(int);
int sum_prime(int);
void print_reserve(int);
void find_gcd(int, int);
void print_n(int);

int cal_sum(int);
int get_int();
void skip_to_int();
int main()
{
    print_number(get_int());
}

int get_int()
{
    cout << "enter a number: ";
    int number{0};
    while (true)
    {
        if (cin >> number)
            return number;
        cout << "sorry that was not a number.\n";
        // get number failed.
        skip_to_int();
    }
}

void skip_to_int()
{
    if (cin.fail())
    {
        cin.clear();
        for (char ch = 0; cin >> ch;)
        {
            if (ch == '-' || isdigit(ch))
                cin.unget();
            return;
        }
    }
    throw runtime_error("input stream terminated.\n");
}

int cal_sum(int x)
{
    return (x) ? x + cal_sum(x - 1) : 0;
}

int cal_sum_square(int x)
{
    return (x) ? x * x + cal_sum_square(x - 1) : 0;
}

void print_number(int x)
{
    int s1 = cal_sum(x);
    cout << "s1: " << s1 << '\n';
    int s2 = cal_sum_square(x);
    cout << "s2: " << s2 << '\n';
}
