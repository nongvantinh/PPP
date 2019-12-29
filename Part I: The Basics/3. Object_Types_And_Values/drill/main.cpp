#include "../../../std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to(Followed by enter):\n";
    string first_name;
    getline(cin, first_name);
    cout << "Dear " << first_name << ",\n";
    cout << "\tHow are you? I'm fine. I miss you.\n";
    cout << "Enter name of another friend: \n";
    string friend_name;
    getline(cin, friend_name);
    cout << "Have you seem " << friend_name << " lately?\n";
    char friend_sex(0);
    cout << "Enter friend sex(f/m):\n";
    cin >> friend_sex;
    switch (friend_sex)
    {
    case 'm':
        cout << "If you see " << friend_name << " please ask him to call me.\n";
        break;
    case 'f':
        cout << "If you see " << friend_name << " please ask her to call me.\n";
        break;
    default:
        cout << "unknow sex.\n";
        break;
    }

    cout << "Age of the recipien: ";
    int friend_age(0);
    cin >> friend_age;
    int min_age(0);
    int max_age(110);
    if (friend_age < min_age || max_age < friend_age)
        throw runtime_error("Are you kidding!\n");
    if (12 < friend_age)
        cout << "Next year you'll be " << friend_age + 1 << '\n';
    else if (17 == friend_age)
        cout << "Next year you'll be able to vote.\n";
    else if (70 < friend_age)
        cout << "I hope you're enjoying your retirement.\n";
    cout << "Yours sincerely,\n\n-- Nong Tinh.\n";
    return 0;
}