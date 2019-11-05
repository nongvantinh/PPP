#include "../std_lib_facilities.h"

int main()
{
    int penies, nickels, dimes, quarters, half_dollars, one_dollars;
    penies = nickels = dimes = quarters = half_dollars = one_dollars = 0;

    cout << "How many pennies do you have?\n";
    cin >> penies;
    cout << "How many nikels do you have?\n";
    cin >> nickels;
    cout << "How many dimes do you have?\n";
    cin >> dimes;
    cout << "How many quarters do you have?\n";
    cin >> quarters;
    cout << "How many half-dollars do you have?\n";
    cin >> half_dollars;
    cout << "How many one-dollars do you have?\n";
    cin >> one_dollars;
    string correct_grammer = (penies > 1) ? " penies.\n" : "peny.\n";
    cout << "You have " << penies << correct_grammer;
    correct_grammer = (nickels > 1) ? " nickels.\n" : "nickel.\n";
    cout << "You have " << nickels << correct_grammer;
    correct_grammer = (dimes > 1) ? " dimes.\n" : "dime.\n";
    cout << "You have " << dimes << correct_grammer;
    correct_grammer = (quarters > 1) ? " quarters.\n" : "quarter.\n";
    cout << "You have " << quarters << correct_grammer;
    correct_grammer = (half_dollars > 1) ? " half dollars.\n" : " half dollar.\n";
    cout << "You have " << half_dollars << correct_grammer;
    correct_grammer = (one_dollars > 1) ? " dollars.\n" : " dollar.\n";
    cout << "You have " << one_dollars << correct_grammer;
    int sum{0};
    sum += penies;
    sum += nickels * 5;
    sum += dimes * 10;
    sum += quarters * 25;
    sum += half_dollars * 50;
    sum += one_dollars * 100;
    cout << "The value of all your coins is: " << sum << " cents" << " or $" << (double)sum / 100 << ".\n";
    return 0;
}