#include <iostream>
#include <vector>
#define DEBUG(x) std::cout << '>' << #x << ": " << x << std::endl

void part1();
int *part1_ex1();
void part1_ex2and3();
void part1_print_array10(std::ostream &os, int *a);
void part1_ex5();
void part1_ex6();
void part1_print_array(std::ostream &os, int *a, int size);
void part1_ex8();
void part1_ex5_with_vector();
void part1_ex6_with_vector();
void part1_print_vector(std::ostream &os, std::vector<int *> &v);
void part1_ex8_with_vector();

void part2();
int *part2_ex1and2();
void part2_ex3nd4();
void part2_10to12_with_array()
{
    int size(10);
    int default_value(1);
    int *p1 = new int[size];
    for (int i(0); i < size; ++i)
    {
        p1[i] = default_value;
        default_value *= 2;
    }
    int *p2 = new int[size];
    for (int i(0); i < size; ++i)
    {
        p2[i] = p1[i];
    }
}

void part2_10to12_with_vector()
{
    int size(10);
    int default_value(1);
    std::vector<int *> v1(size);
    for (int i(0); i < v1.size(); ++i)
    {
        *v1[i] = default_value;
        default_value *= 2;
    }

    std::vector<int *> v2(size);
    for (int i(0); i < v2.size(); ++i)
    {
        *v2[i] = *v1[i];
    }
}

int main()
{
    part1();
    // part2_ex3nd4();

    return 0;
}
void part1()
{
    int *pi = part1_ex1();
    part1_ex2and3();
    part1_print_array10(std::cout, pi);
    part1_ex5();
    part1_ex6();
    part1_print_array(std::cout, pi, 10);
    part1_ex8();
    part1_ex5_with_vector();
    part1_ex6_with_vector();
    std::vector<int *> v(10, new int(0));
    part1_print_vector(std::cout, v);
    part1_ex8_with_vector();
    delete[] pi;
    pi = nullptr;
}

int *part1_ex1()
{
    // Allocate an array of ten ints on the free store using new. Don't forget to initialize it.
    return new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
}

void part1_ex2and3()
{
    // Print ten ints to cout.
    int *pi = part1_ex1();
    for (int i(0); i < 10; ++i)
        std::cout << pi[i] << " ";
    std::cout << std::endl;

    // Dealocate using delete[]
    delete[] pi;
    pi = nullptr;
}

void part1_print_array10(std::ostream &os, int *a)
{
    // Print 10 ints to os.
    for (int i(0); i < 10; ++i)
        os << a[i] << " ";
    std::cout << std::endl;
}

void part1_ex5()
{
    int size{10};
    int *pi = new int[size]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    for (int i(0); i < size; ++i)
        std::cout << pi[i] << " ";
    std::cout << std::endl;

    delete[] pi; // Never forget to deallocate memory.
    pi = nullptr;
}

void part1_ex6()
{
    int size{11};
    int *pi = new int[11]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    for (int i(0); i < size; ++i)
        std::cout << pi[i] << " ";
    std::cout << std::endl;

    delete[] pi; // Never forget to deallocate memory.
    pi = nullptr;
}

void part1_print_array(std::ostream &os, int *a, int size)
{
    // Print size ints to os.
    for (int i(0); i < size; ++i)
        os << a[i] << " ";
    std::cout << std::endl;
}

void part1_ex8()
{

    int size{20};
    int *pi = new int[11]{100};

    // Initialize array.
    for (int i(1); i < size; ++i)
        pi[i] = pi[i - 1] + 1;

    for (int i(0); i < size; ++i)
        std::cout << pi[i] << " ";
    std::cout << std::endl;

    delete[] pi; // Never forget to deallocate memory.
    pi = nullptr;
}

void part1_ex5_with_vector()
{
    std::vector<int *> v{10}; // 10 int* with default value 100.
    int default_value(100);
    for (int i(0); i < v.size(); ++i) // Initialize vector.
    {
        *v[i] = default_value;
        ++default_value;
    }

    for (int i(0); i < v.size(); ++i) // Print out the value of vector.
        std::cout << *v[i] << " ";
    std::cout << std::endl;
}

void part1_ex6_with_vector()
{
    std::vector<int *> v{11}; // 11 int* with default value 100.
    int default_value(100);
    for (int i(0); i < v.size(); ++i) // Initialize vector.
    {
        *v[i] = default_value;
        ++default_value;
    }
    for (int i(0); i < v.size(); ++i) // Print out the value of vector.
        std::cout << *v[i] << " ";
    std::cout << std::endl;
}

void part1_print_vector(std::ostream &os, std::vector<int *> &v)
{
    for (int i(0); i < v.size(); ++i) // Print out the value of vector.
        std::cout << *v[i] << " ";
    std::cout << std::endl;
}

void part1_ex8_with_vector()
{
    std::vector<int *> v(20); // 20 int* with default value 100.
    int default_value(100);
    for (int i(0); i < v.size(); ++i) // Initialize vector.
    {
        *v[i] = default_value;
        ++default_value;
    }

    for (int i(0); i < v.size(); ++i) // Print out the value of vector.
    {
        std::cout << *v[i] << " ";
    }
    std::cout << std::endl;
}

void part2()
{
}

void part2_ex3nd4()
{
    int size(7);
    int default_value(1);
    int *p2 = new int[size];

    for (int i(0); i < size; ++i)
    {
        p2[i] = default_value;
        default_value *= 2;
    }

    for (int i(0); i < size; ++i)
    {
        std::cout << p2 << ": " << *p2 << std::endl;
        ++p2;
    }
    p2 -= size;

    int *p1 = part2_ex1and2();
    int *p3 = p2;
    p2 = p1;
    for (int i(0); i < size; ++i)
    {
        std::cout << p1[i] << " ";
    }
    std::cout << std::endl;
    for (int i(0); i < size; ++i)
    {
        std::cout << p2[i] << " ";
    }
    std::cout << std::endl;

    delete p1;
    p1 = nullptr;
    delete p2;
    p2 = nullptr;
    delete[] p3;
    p3 = nullptr;
}

int *part2_ex1and2()
{
    int *p1 = new int(7);
    std::cout << p1 << std::endl;
    std::cout << *p1 << std::endl;
    return p1;
}
