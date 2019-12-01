#include <iostream>
#include <map>
#include <sstream>

using namespace std;

void init();
string spell_out(int, int);

map<int, string> spell;
int get_range(int, int);
void skip_to_int();
int main() {
    init();
    int number(get_range(10,99));
    int dozens = number / 10;
    int units = number % 10;
    cout << spell_out(dozens, units) << endl;
    return 0;
}

void init() {
    spell[1] = "mot";
    spell[2] = "hai";
    spell[3] = "ba";
    spell[4] = "bon";
    spell[5] = "nam";
    spell[6] = "sau";
    spell[7] = "bay";
    spell[8] = "tam";
    spell[9] = "chin";

    spell[0] = " khong ";
}

// stubborn get number in range inclusive [min:max]
int get_range(int min, int max) {
    cout << "Enter number in range [" << min << ':' << max << ']' << '\n';
    while (true) {
        int number(0);
        if (cin >> number)
            return (min <= number && number <= max) ? number
                                                    : get_range(min, max);
        skip_to_int();
    }
}

void skip_to_int()
{
    if(cin.fail())
    {
        cin.clear();

        for(char ch(' '); cin >> ch;)
        {
            if (isdigit(ch) || ch == '-')
            {
                cin.unget();
                return;
            }
        }

    }
    throw runtime_error("No number found.\n");
}
string spell_out(int dozens, int units) {
    map<int, string>::iterator it;
    ostringstream oss;
    it = spell.find(dozens);
    switch (it->first) {
        case 1:
            oss << "muoi";
            break;
        default:
            oss << it->second << " muoi ";
            break;
    }

    it = spell.find(units);
    switch (it->first) {
        case 0:
            break;
        case 5:
            oss << "lam";
            break;
        default:
            oss << it->second;
            break;
    }
    return oss.str();
}
