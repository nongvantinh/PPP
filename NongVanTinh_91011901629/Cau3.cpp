#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int get_number();
int get_range(int, int);
void skip_to_int();
void fill_arr(vector<int>&);
void even_number(vector<int>&);
int averange(vector<int>&);
void prime(vector<int>&);
void perfect_number(vector<int>&);

bool is_prime(int);
bool is_perfect_number(int);

int main() {
    const int size(get_range(0, 100));

    vector<int> arr(size);
    fill_arr(arr);
    even_number(arr);
    cout << averange(arr) << endl;
    prime(arr);
    perfect_number(arr);

    return 0;
}

void prime(vector<int>& arr) {
    cout << "Prime number.\n";
    int count(0);
    for (int& i : arr)
        if (is_prime(i)) {
            ++count;
            cout << i << endl;
        }

    if (!count) cout << "There is no prime number in this array.\n";
}

void perfect_number(vector<int>& arr) {
    cout << "Perfect number.\n";
    int count(0);
    for (int& i : arr)
        if (is_perfect_number(i)) {
            ++count;
            cout << i << endl;
        }

    if (!count) cout << "There is no perfect number in this array.\n";
}
void even_number(vector<int>& arr) {
    for (int& i : arr)
        if (!(i % 2)) cout << i << endl;
}

int averange(vector<int>& arr) {
    int result(0);
    for (int& i : arr) result += i;

    return result / arr.size();
}

bool is_perfect_number(int n) {
    // n is Square root?
    int sum{0};
    for (int i(2); i <= n; i++) {
        if (n % i == 0)  // This is prime number.
        {
            int uoc_so = n / i;
            sum += uoc_so;
        }
    }
    return sum == n;
}

bool is_prime(int n) {
    // Corner case
    if (n <= 1) return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0) return false;

    return true;
}
void fill_arr(vector<int>& arr) {
    srand(time(NULL));
    for (int& i : arr) {
        i = rand() %100 +1;
    }
}

int get_number() {
    cout << "Enter number: ";
    while (true) {
        int number(0);
        if (cin >> number) return number;
        skip_to_int();
    }
}
// stubborn get number in range exclusive [min:max]
int get_range(int min, int max) {
    cout << "Enter number in range (" << min << ':' << max << ')';
    int number(get_number());
    return (min < number && number < max) ? number : get_range(min, max);
}

void skip_to_int() {
    if (cin.fail()) {
        cin.clear();

        for (char ch(' '); cin >> ch;) {
            if (isdigit(ch) || ch == '-') {
                cin.unget();
                return;
            }
        }
    }
    throw runtime_error("No number found.\n");
}

