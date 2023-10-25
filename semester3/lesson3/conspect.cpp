#include<iostream>
// using namespace std;

class Rational
{
public:
    Rational(Rational&& other) {} (std::swap(other.m_num, m_num));
    operator = (Rational&& other)
private:
    int m_num;
    int m_denom;
};

Array
{
    Array(Array&& other)
    {
        swap(m_size, other.m_size);
        swap(m_data, other.m_data);
    }
    unsigned m_size;
    T* m_data;
};