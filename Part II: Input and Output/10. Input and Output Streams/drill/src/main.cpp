#include "../../../../std_lib_facilities.h"
using namespace std;
struct Point
{
    Point(){};
    Point(int p_x, int p_y) : x{p_x}, y{p_y} {}
    int x{0}, y{0};
    bool operator==(const Point &p2)
    {
        return x != p2.x &&
               y != p2.y;
    }
};

bool operator!=(const Point p1, const Point &p2)
{
    return p1 != p2;
}

// Input format (x,y)
istream &operator>>(istream &ist, Point &p)
{

    char open{' '}, comma{' '}, close{' '};
    int x{0}, y{0};
    ist >> open >> x >> comma >> y >> close;
    if (!ist)
    {
        if (ist.eof())
            return ist;
        else if (ist.bad())
            throw runtime_error("bad read.\n");
        if (ist.fail())
        {
            ist.clear();

            for (char ch{' '}; ist >> ch;)
            {
                if (ch != ')')
                    throw runtime_error("Bad read from file.\n");
            }
        }
    }

    if (open != '(' || comma != ',' || close != ')')
    {
        ist.clear(ios_base::failbit);
        return ist;
    }
    p = Point{x, y};
    return ist;
}

ostream &operator<<(ostream &ost, const Point p)
{
    return ost << '(' << p.x << ',' << p.y << ')';
}

void fill_vector(istream &, vector<Point> &, char);
void print_vector(ostream &, const vector<Point> &);
void write_to_file(ofstream &, string, const vector<Point> &);
void read_from_file(ifstream &, string, const vector<Point> &);

int main()
{
    string fname{"mydata.txt"};
    ofstream ost{fname};
    if (!ost)
        error("Can't open ouput file name: ", fname);
    ifstream ist{fname};
    if (!ist)
        error("Can't open input file name: ", fname);

    cout << "Let's enter seven (x,y) pairs.\n";
    vector<Point> original_points;
    fill_vector(cin, original_points, '.');

    cout << "All pairs are.\n";
    print_vector(cout, original_points);

    cout << "Write all pairs point to file...\n";
    write_to_file(ost, fname, original_points);

    vector<Point> processed_points;
    cout << "Processed point.\n";

    for (Point p; ist >> p;)
        processed_points.push_back(p);

    cout << "All processed points are.\n";
    for (Point p : processed_points)
        cout << p << endl;

    for (int i(0); i < original_points.size(); ++i)
    {
        if (original_points[i] != processed_points[i])
            throw runtime_error("Something's wrong!\n");
    }
}

void fill_vector(istream &ist, vector<Point> &v, char terminator)
{
    ist.exceptions(ios_base::badbit);
    for (Point p; ist >> p;)
        v.push_back(p);
    if (ist.eof())
        return;

    // Not good(), not bad(), not eof().
    ist.clear();
    char c{' '};
    ist >> c;
    if (c != terminator)
    {
        ist.unget();
        ist.clear(ios_base::failbit);
    }
}

void print_vector(ostream &ost, const vector<Point> &v)
{
    for (Point p : v)
        ost << p << endl;
}
void write_to_file(ofstream &ost, string fname, const vector<Point> &v)
{
    if (!ost.is_open())
        ost.open(fname);
    if (!ost)
    {
        if (ost.eof())
            return;
        else if (ost.bad())
            throw runtime_error("link to output file broken.\n");
        else if (ost.fail())
        {
            // somehow recover.
        }
    }
    for (Point p : v)
        ost << p << endl;
}
void read_from_file(ifstream &ist, string fname, const vector<Point> &v)
{
    if (!ist.is_open())
        ist.open(fname);

    if (!ist)
    {
        if (ist.eof())
            return;
        else if (ist.bad())
            throw runtime_error("link to output file broken.\n");
        else if (ist.fail())
        {
            // somehow recover.
        }
    }
    for (Point p : v)
        ist >> p;
}