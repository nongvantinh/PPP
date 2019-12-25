/*
2. Write a program that creates a file of data in the form of the temperature Reading type defined in §10.5. For testing, fill
the file with at least 50 “temperature readings.” Call this program store_temps.cpp and the file it creates
raw_temps.txt.
*/

#include <iostream>
#include <fstream>
#include <vector>
// A tempature of reading.
struct Reading
{
    int hour{0};        // hour after midnight [0:23]
    double temperature; // in Fahrenherit.
};

std::ostream &operator<<(std::ostream &ost, const Reading &r)
{
    return ost << r.hour << ' ' << r.temperature << std::endl;
}

void write_to_file(std::vector<Reading> &data);
void fill_vector(std::vector<Reading> &v);
int main()
{

    std::vector<Reading> v;
    fill_vector(v);
    write_to_file(v);
    return 0;
}
void write_to_file(std::vector<Reading> &data)
{
    std::ofstream ost{"taw_temp.txt"};
    if (!ost)
        throw std::runtime_error("Can't open file for writing.\n");
    for (Reading i : data)
    {
        ost << i;
    }
}
void fill_vector(std::vector<Reading> &v)
{
    srand(time(NULL));
    int hour(0);
    for (int i(0); i < 60; ++i)
    {
        Reading r;
        r.hour = hour;
        r.temperature = rand() % 60;
        v.push_back(r);
        hour = (23 <= hour) ? 0 : ++hour;
    }
}
