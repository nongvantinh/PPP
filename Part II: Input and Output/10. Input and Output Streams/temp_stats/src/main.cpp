/*
4. Modify the store_temps.cpp program from exercise 2 to include a temperature suffix c for Celsius or f for Fahrenheit
temperatures. Then modify the temp_stats.cpp program to test each temperature, converting the Celsius readings to
Fahrenheit before putting them into the vector.
*/

#include <iostream>
#include <fstream>
#include <vector>
// A tempature of reading.
struct Reading
{
    Reading() {}
    Reading(int h, double temp) : hour(h), temperature(temp) {}
    int hour{0};             // hour after midnight [0:23]
    double temperature{0.0}; // in Fahrenherit.
};

std::ostream &operator<<(std::ostream &ost, const Reading &r)
{
    return ost << r.hour << ' ' << r.temperature << std::endl;
}
std::istream &operator>>(std::istream &ist, Reading &r)
{
    int hour(0);
    double temp(0);
    ist >> hour >> temp;
    if (!ist)
    {
        if (ist.bad())
            throw std::runtime_error("bad() read\n");
        else if (ist.eof())
            return ist;
        else // fail().
        {
            ist.clear();
            char ch;
            ist >> ch;
            std::cout << ch;
            ist.unget();
            ist.clear(std::ios_base::failbit);
            throw std::runtime_error("read fail().\n");
        }
    }
    r = Reading(hour, temp);
    return ist;
}

template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
						// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}


std::vector<Reading> get_temps();
void fill_vector(std::vector<Reading> &v);
int main()
{

    std::vector<Reading> v;
    v = get_temps();
    double median(0);
    for (Reading r : v)
    {
        median += r.temperature;
    }
    median /= v.size();
    std::cout << "median: " << median << std::endl;
    return 0;
}

std::vector<Reading> get_temps()
{
    std::ifstream ist{"taw_temp.txt",std::ios_base::binary};
    if (!ist)
        throw std::runtime_error("Can't open file for reading.\n");
    std::vector<Reading> v;
    for (Reading i(0, 0.0); ist.read(as_bytes(i),sizeof(Reading));)
    {
        v.push_back(i);
    }
    return v;
}

void fill_vector(std::vector<Reading> &v)
{
    srand(time(NULL));
    int hour(0);
    for (int i(0); i < 60; ++i)
    {
        Reading r(0, 0.0);
        r.hour = hour;
        r.temperature = rand() % 60;
        v.push_back(r);
        hour = (23 <= hour) ? 0 : ++hour;
    }
}
