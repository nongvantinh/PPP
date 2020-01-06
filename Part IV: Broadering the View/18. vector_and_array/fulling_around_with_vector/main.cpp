#include <iostream>
#include <vector>

int main()
{
    std::vector<double> v(30);
    for (int i(0); i < 1; ++i)
        v.push_back(i);
    std::cout << "v.size(): " << v.size() << std::endl;
    std::cout << "v.capacity()" << v.capacity() << std::endl;

    return 0;
}