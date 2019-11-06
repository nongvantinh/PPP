#include "../std_lib_facilities.h"

int main()
{
    double current_rice{1};
    double sum{0};
    for (int i(1); i <= 64; ++i)
    {
        sum += current_rice;
        cout << i << " square: " << current_rice << " sum so far: " << sum << '\n';
        current_rice *= 2;
    }
    return 0;
}