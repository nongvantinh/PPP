#include "../std_lib_facilities.h"

int main()
{
    cout << "enter range max number: ";
    int range{0};
    cin >> range;
    cout << "enter n to find n primes: ";
    int n{0};
    cin >> n;

    vector<int> marked(range, 1);
    for (int i(2); i <= sqrt(marked.size()); ++i)
    {
        int increment(2);
        if (marked[i])
        {
            for (int j(i * i); j < marked.size(); j = i * increment)
            {
                marked[j] = 0;
                ++increment;
            }
        }
    }

    vector<int> n_primes;
    for (int i(2); i < marked.size(); ++i)
    {
        if (marked[i])
            n_primes.push_back(i);
    }

    for (int &i : n_primes)
    {
        if (!n)
            break;
        cout << i << ' ';
        --n;
    }
    cout << '\n';
    return 0;
}
