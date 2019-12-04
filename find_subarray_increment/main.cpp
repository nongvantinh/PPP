#include <chrono>
#include <iostream>
#include <vector>

#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

using namespace std;
using namespace std::chrono;

class Position {
   public:
    Position() : m_begin(0), m_end(0){};
    Position(int begin) : m_begin(begin){};
    Position(int begin, int end) : m_begin(begin), m_end(end) {
        if (begin < 0)
            throw runtime_error("negative value for begin of array.\n");
        if (end < 0) throw runtime_error("negative value for end of array.\n");
    };
    int begin() const { return m_begin; }
    void set_begin(int begin) {
        if (begin < 0)
            throw runtime_error("negative value for begin of array.\n");
        m_begin = begin;
    }
    int end() const { return m_end; }
    void set_end(int end) {
        if (end < 0) throw runtime_error("negative value for end of array.\n");
        m_end = end;
    }
    int distance() const { return end() - begin(); }
    inline bool operator<(Position& pos) const {
        return this->distance() < pos.distance();
    }
    inline bool operator>(Position& pos) const {
        return this->distance() > pos.distance();
    }
    inline bool operator==(Position& pos) const {
        return this->distance() == pos.distance();
    }

   private:
    int m_begin;
    int m_end;
};

// return the position of subarray in list.
vector<Position> detech_subarray(const vector<double>&);
vector<Position> update_subarray(vector<Position>&, Position);
void print_arr(vector<double>&, const Position&);

int main() {
    cout << "find the largest subarray in list.\n";
    vector<double> arr{4, 6, 2, 5, 7, 8, 7, 7, 5,  1,  2,   1,
                       2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 133, 45,
                       6, 1, 2, 3, 4, 5, 6, 7, 8,  9,  10,  11};
    cout << "size: " << arr.size() << endl;

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    vector<Position> list_pos = detech_subarray(arr);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds\n";

    for (Position& pos : list_pos) {
        cout << "This subarray.\n";
        // print the sub array we've found.
        print_arr(arr, pos);
    }
    return 0;
}

/// @brief
/// This function will find the length of the largest subarray in "arr".
/// @param arr : The array we want to find the largest subarray.
/// @return : return a vector position of the largest subarray in arr or largest
/// subarray have equal length.
vector<Position> detech_subarray(const vector<double>& arr) {
    vector<Position> pos(1);
    Position largest;

    // walk through the vector and get the largest subarray.
    for (int i(1); i < arr.size(); ++i) {
        if (arr[i - 1] <= arr[i])
            // length of this subarray keep grow up. Update it.
            largest.set_end(i);
        else {  // subarray end here.

            pos = update_subarray(pos, largest);

            // reset current subarray prepare for the new one.
            largest.set_begin(i);
        }
    }

    // corner case the largest subarray is placed in the end.
    pos = update_subarray(pos, largest);
    return pos;
}

vector<Position> update_subarray(vector<Position>& arr, Position subarray) {
	if (!arr.size())
	throw runtime_error("array is empty.\n");

    if (arr[0] < subarray) {  // compare with the current largest subarray.
        arr.clear();  // This subarray is the largest. Remove the old return the
                      // largest.
        arr.push_back(subarray);
    } else if (arr[0] == subarray)  // two subarrays have same length.
        arr.push_back(subarray);
    return arr;
}

void print_arr(vector<double>& arr, const Position& pos) {
	if(!arr.size())
	throw runtime_error("array is empty.\n");
    for (int i(pos.begin()); i <= pos.end(); ++i) {
        cout << "arr[" << i << ']' << arr[i] << endl;
    }
}
