#include <cmath>
#include <iostream>

using namespace std;

int get_number();
int get_range(int, int);
void skip_to_int();
bool is_square_number(double);
void performances(int, int);

int main() {
    double number(get_number());
    cout << number << " is square number? " << is_square_number(number) << endl;
    performances(number, 2);
    cout << '\n';
    return 0;
}
void performances(int number, int base) {
    int b = number % base;
    number = number / base;
    if (number) performances(number, base);
    cout << b;
}
bool is_square_number(double number) {
    return (int)sqrt(number) == sqrt(number);
}
int get_number() {
    cout << "Enter number: ";
    while (true) {
        int number(0);
        if (cin >> number) return number;
        skip_to_int();
    }
}
// stubborn get number in range inclusive [min:max]
int get_range(int min, int max) {
    cout << "Enter number in range [" << min << ':' << max << ']';
    int number(get_number());
    return (min <= number && number <= max) ? number : get_range(min, max);
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

