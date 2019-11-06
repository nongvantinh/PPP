#include "../std_lib_facilities.h"
bool sha256sum(string &, string &);
int get_score_by_name(vector<string> &, vector<int> &);
void print_name_by_score(vector<string> &, vector<int> &);

int main()
{
    vector<string> list_names;
    vector<int> scores;
    cout << "enter name and score: ";
    string name;
    while (true)
    {
        int score{0};
        cin >> name >> score;
        if (name == "NoName" && !score)
            break;

        for (string &i : list_names)
            if (i == name)
                error("name enter twice.\n");

        list_names.push_back(name);
        scores.push_back(score);
    }
    cout << get_score_by_name(list_names, scores) << '\n';
    print_name_by_score(list_names, scores);

    return 0;
}
int get_score_by_name(vector<string> &names, vector<int> &scores)
{
    string name;
    cout << "get score by name: ";
    cin >> name;
    for (int i(0); i < names.size(); ++i)
    {
        if (name == names[i])
        {
            return scores[i];
        }
    }
    cout << "name not found.\n";
}
void print_name_by_score(vector<string> &names, vector<int> &scores)
{
    int score{0};
    cout << "get name by score: ";
    cin >> score;
    for (int i(0); i < scores.size(); ++i)
    {
        if (score == scores[i])
            cout << names[i] << '\n';
    }
}

bool sha256sum(string &s1, string &s2)
{
    return s1 == s2;
}