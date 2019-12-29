#include "../std_lib_facilities.h"

int main()
{
    vector<double> distances;

    for (double distance{0.0}; cin >> distance;)
        distances.push_back(distance);

    sort(distances);

    double total_distances{0.0};
    for (double &distance : distances)
        total_distances += distance;
    cout << "total distance: " << total_distances << '\n';
    cout << "the smallest distance: " << distances[0] << '\n';
    cout << "this largest distance: " << distances[distances.size() - 1] << '\n';
    return 0;
}