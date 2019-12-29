#include <iostream>

class B1
{
public:
    virtual void vf()
    {
        std::cout << "virtual function B1::vf() is called!\n";
    }
    void f()
    {
        std::cout << "non-virtual function B1::f() is called!\n";
    }
};

class D1 : public B1
{
public:
    void vf() override
    {
        std::cout << "virtual function D1::vf() is called!\n";
    }
};

int main()
{
    B1 b1;
    b1.vf();
    b1.f();

    D1 &d1 = B1();
    d1.vf();
    d1.f();
    return 0;
}