#include <iostream>
#include <vector>

std::vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(std::vector<int> &v);
int factorial(int n)
{
    int value(1);
    for (int i(n); i > 0; --i)
        value *= i;
    return value;
}
int main()
{
    f(gv);
    std::cout << "----------------------------------------" << std::endl;
    std::vector<int> vv;
    for (int i(0); i < gv.size(); ++i)
        vv.push_back(factorial(i + 1));
    f(vv);
    return 0;
}
void f(std::vector<int> &v)
{
    std::vector<int> lv(gv.size());
    lv = gv;

    for (int &i : lv)
        std::cout << "lv: " << i << std::endl;
    std::vector<int> lv2(v.size());
    lv2 = v;
    for (int &i : lv2)
        std::cout << "lv2: " << i << std::endl;
}
