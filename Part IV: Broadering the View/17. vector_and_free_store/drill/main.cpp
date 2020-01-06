#include <iostream>
#include <vector>
void init_array(int *arr, int size);
void print_array10(std::ostream &os, int *a, int size);
void init_vector(std::vector<int *> &v, int size);
void print_vector(std::ostream &os, std::vector<int *> &a);

void print_int(int *pi, int size);
int main()
{

    std::vector<int> v(10);
    int init(1);
    v.push_back( int(init));
    for (int i(0); i < 10; ++i)
    {
        init *= 2;
        v.push_back( int(init));
    }
    std::vector<int> v2(v);
    for (int i(0); i < v2.size(); ++i)
        std::cout << "v2: " << v2[i] << std::endl;
    return 0;
}
void print_int(int *pi, int size)
{
    for (size_t i(0); i < size; ++i)
    {
        std::cout << "pointed-to: " << pi[i] << std::endl;
    }
}

void init_vector(std::vector<int *> &v, int size)
{
    int init_value(1);
    for (int i(0); i < size; ++i)
    {
        v.push_back(new int(init_value));
        init_value *= 2;
    }
}

void init_array(int *ip, int size)
{
    *ip = 100;
    for (int i(1); i < size; ++i)
    {
        ip[i] = ip[i - 1] + 1;
    }
}

void print_array10(std::ostream &os, int *a, int size)
{
    for (int i(0); i < size; ++i)
        os << a[i] << std::endl;
}
void print_vector(std::ostream &os, std::vector<int *> &a)
{
    for (size_t i(0); i < a.size(); ++i)
    {
        os << *a[i] << std::endl;
    }
}