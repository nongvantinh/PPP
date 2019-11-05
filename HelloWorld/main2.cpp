#include "../std_lib_facilities.h"

int main()
{
    string s = "programmingisunderstanding";
    string s2 = "rememberthingsneedtimes";

    if (s == s2)
        cout << "Yeah\n";
    cout << s2.size() << "\t" << s << '\n';
    return 0;
}