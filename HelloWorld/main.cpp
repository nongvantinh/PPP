#include "../std_lib_facilities.h"

using namespace std;

// read name and age (2nd version)
int main()
{
    cout << "Please enter a floating-point value: ";
    int n(0);
    cin >> n;
    cout << "n == " << n
         << "\nn + 1 == " << n + 1
         << "\nthree times n == " << 3 * n
         << "\ntwice n == " << n + n
         << "\n squared == " << n * n
         << "\nhaft of n == " << n / 2
         << "\nsqure root of n == " << sqrt(n)
         << '\n'; // Another name for newline ("end of line") int output.
}