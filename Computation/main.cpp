#include "../std_lib_facilities.h"

using namespace std;

int main()
{

    cout << "Start word: ";
    string privious;
    string current;
    int count(0);

    while (cin >> current)
    {
        if (current == privious)
        {
            ++count;
            cout << "Repeated word: " << current << count << endl;
        }
        privious = current;
    }
}