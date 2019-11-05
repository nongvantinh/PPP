#include <iostream>

using namespace std;

double square(double);

int main()
{
    cout << "Enter a, b: ";
    double a, b;
    a = b = 0;
    cin >> a >> b;
    if (a < 0 || b < 0)
        throw runtime_error("a or b less than 0.\n");
    double sum(0);
    for (int i(a); i <= b; ++i)
        sum += square(i);
    cout << "sum: " << sum << endl;
    return 0;
}

double square(double num)
{
    return num * num;
}