#include <iostream>

class Vector
{
public:
    int size() const
    {
        return m_size;
    }

    Vector() : m_elem(nullptr), m_size(0)
    {
    }
    explicit Vector(int p_size) : m_elem(new double[p_size]), m_size(p_size)
    {
        for (int i(0); i < size(); ++i) // Don't forget to initialize elements.
        {
            m_elem[i] = 0.0;
        }
    }
    Vector(const Vector &arg)
        : m_size(arg.size()), m_elem(new double[size()])
    {
        std::copy(arg.m_elem, arg.size(), m_elem);
    }

    Vector(std::initializer_list<double> lst)
        : m_size(lst.size()), m_elem(new double[size()])
    {
        std::copy(lst.begin(), lst.end(), m_elem);
    }
    Vector(Vector &&arg)
        : m_size(arg.size), m_elem(arg.m_elem)
    {
        arg.m_size = 0;
        arg.m_elem = nullptr;
    }
    Vector &operator=(const Vector &arg)
    {
        double *p = new double[arg.size()];
        std::copy(arg.m_elem, arg.m_elem + arg.size(), m_elem);
        delete[] m_elem;
        m_elem = p;
        m_size = arg.size();
        return *this;
    }
    double &operator[](int index)
    {
        return m_elem[index];
    }
    double &operator[](int index) const
    {
        return m_elem[index];
    }
    ~Vector()
    {
        delete[] m_elem;
    }
    double get_elem(int p_index) const
    {
        if (p_index < 0)
            throw std::runtime_error("Negative index.\n");
        return m_elem[p_index];
    }

    void set_elem(int p_index, double value)
    {
        if (p_index < 0)
            throw std::runtime_error("Negative p_index.\n");
        m_elem[p_index] = value;
    }

private:
    double *m_elem{nullptr};
    int m_size{0};
};

void sizes(char ch, bool b, int i, float f, double d);

int main()
{
    // Vector v(4);
    // v.set_elem(0, 0.33);
    // v.set_elem(1, 22);
    // v.set_elem(2, 27.2);
    // v.set_elem(3, 54.2);

    // for (int i(0); i < v.size(); ++i)
    // {
    //     std::cout << "v[" << i << "] = " << v.get_elem(i) << std::endl;
    // }

    sizes('c', true, 17, 222.2, 444.4);
    return 0;
}
void sizes(char c, bool b, int i, float f, double d)
{
    std::cout << "char*  \t: " << sizeof(char *) << std::endl;
    std::cout << "bool*  \t: " << sizeof(bool *) << std::endl;
    std::cout << "int*   \t: " << sizeof(int *) << std::endl;
    std::cout << "float* \t: " << sizeof(float *) << std::endl;
    std::cout << "double*\t: " << sizeof(double *) << std::endl;
    std::cout << "-----------------------------------------------\n";
    std::cout << "char  \t: " << sizeof(char) << std::endl;
    std::cout << "bool  \t: " << sizeof(bool) << std::endl;
    std::cout << "int   \t: " << sizeof(int) << std::endl;
    std::cout << "float \t: " << sizeof(float) << std::endl;
    std::cout << "double\t: " << sizeof(double) << std::endl;
    std::cout << "-----------------------------------------------\n";
    std::cout << "c    \t: " << sizeof(c) << std::endl;
    std::cout << "b    \t: " << sizeof(b) << std::endl;
    std::cout << "i    \t: " << sizeof(i) << std::endl;
    std::cout << "f    \t: " << sizeof(f) << std::endl;
    std::cout << "d    \t: " << sizeof(d) << std::endl;
    std::cout << "-----------------------------------------------\n";
    char *cha = new char();
    bool *boo = new bool();
    int *in = new int();
    float *flo = new float();
    double *dou = new double();
    std::cout << "*char  \t: " << sizeof(*cha) << std::endl;
    std::cout << "*bool  \t: " << sizeof(*boo) << std::endl;
    std::cout << "*int   \t: " << sizeof(*in) << std::endl;
    std::cout << "*float \t: " << sizeof(*flo) << std::endl;
    std::cout << "*double\t: " << sizeof(*dou) << std::endl;
    std::cout << "-----------------------------------------------\n";
    std::cout << "Freeing dinamic memory...\n";
    delete cha;
    delete boo;
    delete in;
    delete flo;
    delete dou;
    std::cout << "Dinamic memory is now freed.\n";
}
