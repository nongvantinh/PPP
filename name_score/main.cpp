#include "../std_lib_facilities.h"
class ValueNotFound {};
class NameNotFound {};
class Name_value {
   public:
    Name_value() {}
    Name_value(string name, int value) : m_name(name), m_value(value) {}
    string name() { return m_name; }
    int value() { return m_value; }

   private:
    string m_name;
    int m_value;
};
bool sha256sum(string &, string &);
int get_score_by_name(vector<Name_value> &);
string get_name_by_score(vector<Name_value> &);
void print_all(vector<Name_value> &);
void print_score_by_name(vector<Name_value> &);
void print_name_by_score(vector<Name_value> &);
int main() {
    vector<Name_value> name_value;
    vector<string> list_names;
    vector<int> scores;
    cout << "enter name and score: ";
    string name;
    while (true) {  // insert name & score.
        int score{0};
        cin >> name >> score;
        if (name == "NoName" && !score) break;  // terminate input.
        // Is this name already have in list?
        for (int i(0); i < name_value.size(); ++i)
            if (name_value[i].name() == name) error("name enter twice.\n");
        name_value.push_back(Name_value(name, score));
    }
    print_all(name_value);

    return 0;
}

void print_score_by_name(vector<Name_value> &name_value) {
    try {
        int score = get_score_by_name(name_value);
        cout << score << '\n';
    } catch (ValueNotFound &e) {
        cout << "Score not found!.\n";
    }
}
void print_name_by_score(vector<Name_value> &name_value) {
    try {
        cout << "name: " << get_name_by_score(name_value);
    } catch (NameNotFound &e) {
        cout << "Name not found!\n";
    }
}
void print_all(vector<Name_value> &name_value) {
    for (int i(0); i < name_value.size(); ++i) {
        cout << name_value[i].name() << ' ' << name_value[i].value() << '\n';
    }
}
int get_score_by_name(vector<Name_value> &name_value) {
    string name;
    cout << "get score by name: ";
    cin >> name;
    for (int i(0); i < name_value.size(); ++i) {
        if (name == name_value[i].name()) {
            return name_value[i].value();
        }
    }
    throw ValueNotFound();
}
string get_score_by_value(vector<Name_value> &name_value) {
    int score{0};
    cout << "get name by score: ";
    cin >> score;
    for (int i(0); i < name_value.size(); ++i) {
        if (score == name_value[i].value()) return name_value[i].name();
    }
    throw NameNotFound();
}

bool sha256sum(string &s1, string &s2) { return s1 == s2; }
