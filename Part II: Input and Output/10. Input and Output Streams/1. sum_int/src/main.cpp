// 1. Write a program that produces the sum of all the numbers in a file of whitespace-separated integers.
#include <iostream>
#include <fstream>

using namespace std;

int sum_int(const string &fname);

int main()
{
    string fname("dat.conf");
    cout << "sum: " << sum_int(fname) << endl;

}
int sum_int(const string &fname)
{
    ifstream ist{fname};
    if (!ist)
    {
        string msg = "Can't open file to read. File name" + fname;
        throw runtime_error(msg);
    }
    int sum(0);
    for (int number(0); ist >> number;)
    {
        sum += number;
    }
    return sum;
}
