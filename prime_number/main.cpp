#include "../std_lib_facilities.h"
bool is_prime(int);
void fill_primes(int, int, vector<int> &);
int get_int();
void skip_to_int();

int main()
{
    vector<int> primes;
    cout << "enter range max: ";
    int range{0};
    cin >> range;
    fill_primes(1, range, primes);

    for (int &i : primes)
    {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}

void fill_primes(int min, int max, vector<int> &primes)
{
    for (int i(min); i <= max; ++i)
    {
        if (is_prime(i))
            primes.push_back(i);
    }
}

int get_int()
{
    while (true)
    {
        int number{0};
        if (cin >> number)
        {
            return number;
        }
        skip_to_int();
    }
}

void skip_to_int()
{
    if (cin.fail())
    {
        cin.clear();
        for (char ch(' '); cin >> ch;)
        {
            if (ch == '-' || isdigit(ch))
            {
                cin.unget();
                return;
            }
        }
    }
    throw runtime_error("eof().\n");
}

bool is_prime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}