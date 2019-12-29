#include "../std_lib_facilities.h"

enum Money
{
    none = 0,
    yen,
    euro,
    pound,
    yuan,
    kroner
};

int main()
{

    double yen_to_dollars{0.0092}; // 1 yen == 0.0092 dollars.
    double euro_to_dollar{1.11};
    double pound_to_dollar{1.29};
    double yuan_to_dollar{0.14};
    double kroner_to_dollar{0.11};

    int unit(0);
    double money{0.0};
    cout << "choose type convert:  "
         << "\n1. yen to dollar."
         << "\n2. euro to dollar."
         << "\n3. pound to dollar."
         << "\n4. yuan to dollar."
         << "\n5. kroner to dollar.\n";
    cin >> unit;
    cout << "Enter money you have: ";
    cin >> money;
    switch (unit)
    {

    case 1:
        cout << money << " yens == " << money * yen_to_dollars << " dollars.\n";
        break;
    case 2:
        cout << money << " euros == " << money * euro_to_dollar << " dollars.\n";
        break;
    case 3:
        cout << money << " pounds == " << money * pound_to_dollar << " dollars.\n";
        break;
    case 4:
        cout << money << " yuan == " << money * yuan_to_dollar << " dollars.\n";
        break;
    case 5:
        cout << money << " kroner == " << money * kroner_to_dollar << " dollars\n";
        break;
    default:
        cout << "Sorry, did you just typing too quick.\n";
        break;
    }
    return 0;
}