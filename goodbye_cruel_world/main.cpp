#include "../std_lib_facilities.h"

int main()
{

    cout << "Enter the name of the persion you want to write to: ";
    string fist_name;
    cin >> fist_name;
    cout << "Enter age: ";
    int age{0};
    cin >> age;
    cout << "Enter the name of the friend: ";
    string friend_name;
    cin >> friend_name;
    cout << "Enter friend sex (m/f): ";
    char friend_sex{'0'};
    cin >> friend_sex;
    cout << "Dear, " << fist_name << endl;
    cout << "\tHow are you? I'm fine. I miss you\n"
         << "Have you seen " << friend_name << " lately.\n";
    if (friend_sex == 'f')
        cout << "If you see " << friend_name << " please ask her to call me.\n";
    else if (friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    if (age < 0 || 110 < age)
        simple_error("you're kidding!");
    else
        cout << "I hear you just had a birthday and you are " << age << " year olds" << endl;

    if (age < 12)
        cout << "Next year you'll be " << age + 1 << '\n';
    else if (age == 17)
        cout << "Next year you will be able to vote.\n";
    else if (70 < age)
        cout << "I hope you are enjoying retirement.\n";

    cout << "Yours sincerely,"
         << "\n\n"
         << "Tinh.\n";
}