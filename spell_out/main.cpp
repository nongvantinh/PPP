#include "../std_lib_facilities.h"

string number_to_string(int);
int string_to_number(string);
int get_int();
int get_range(int, int);
void skip_to_int();

int main()
{
    string s;
    cin >> s;
    cout << string_to_number(s) << '\n';
    return 0;
}

string number_to_string(int number)
{
    vector<string> list_number;
    list_number.push_back("zero");
    list_number.push_back("one");
    list_number.push_back("two");
    list_number.push_back("three");
    list_number.push_back("four");
    list_number.push_back("five");
    list_number.push_back("six");
    list_number.push_back("seven");
    list_number.push_back("eight");
    list_number.push_back("nine");
    return list_number[number];
}

int string_to_number(string spell)
{
    if (spell == "zero")
        return 0;
    else if (spell == "one")
        return 1;
    else if (spell == "two")
        return 2;
    else if (spell == "three")
        return 3;
    else if (spell == "four")
        return 4;
    else if (spell == "five")
        return 5;
    else if (spell == "six")
        return 6;
    else if (spell == "seven")
        return 7;
    else if (spell == "eight")
        return 8;
    else if (spell == "nine")
        return 9;
}

int get_range(int min, int max)
{
    int number = get_int();
    return (min <= number && number <= max) ? number : get_range(min, max);
}
int get_int()
{
    while (true)
    {
        int number{0};
        if (cin >> number)
            return number;
        cout << "Sorry that was not the number.Please try again.\n";
        skip_to_int();
    }
}
void skip_to_int()
{
    if (cin.fail())
    {
        cin.clear(); // clear the stream.

        for (char ch; cin >> ch;)
        {
            if (ch == '-' || isdigit(ch))
            {
                cin.unget();
                return;
            }
        }
    }
    throw runtime_error("eof().\n");
}