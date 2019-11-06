#include "../std_lib_facilities.h"

int main()
{
    vector<double> temps;
    for(double temp{0.0}; cin >> temp;)
        temps.push_back(temp);

        sort(temps);

    cout << "median: " << temps[temps.size()/2] << '\n';
    return 0;
}