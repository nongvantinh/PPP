#include <iostream>

int ga[10]{1, 2, 4, 8, 16, 32, 64, 128, 512, 1024};
void f(int a[], int size);
int factorial(int n);
int main()
{
    int size(10);
    // f(ga, size);
    int aa[size];
    for (int i(0); i < size; ++i)
    {
        aa[i] = factorial(i + 1);
    }
    f(aa, size);
    return 0;
}
int factorial(int n)
{
    int value(1);
    for (int i(n); i > 0; --i)
        value *= i;
    return value;
}

void f(int a[], int size)
{
    int la[10];
    for (int i(0); i < size; ++i)
    {
        la[i] = ga[i];
        std::cout << "elem of la: " << la[i] << std::endl;
    }

    int *p = new int[size];
    for (int i(0); i < size; ++i)
    {
        p[i] = a[i];
        std::cout << "elem of p: " << p[i] << std::endl;
    }
    delete[] p;
}
