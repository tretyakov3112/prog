#pragma once
#include<iostream>

struct Cls {
    Cls(char c, double d, std::int32_t i)
        : m_c(c)
        , m_d(d)
        , m_i(i)
    {}
private:
    char m_c;
    double m_d;
    std::int32_t m_i;
};

struct Fo
{
    Fo(char c, double d, int i)
        : m_c(c)
        , m_d(d)
        , m_i(i)
    {}
public:
    char m_c;
    double m_d;
    int m_i;
};


char& get_c(Cls& cls) {
    Fo * c = reinterpret_cast<Fo*>(&cls);
    return c->m_c;
}

double& get_d(Cls& cls) {
    Fo * d = reinterpret_cast<Fo*>(&cls);
    return d->m_d;
}

int& get_i(Cls& cls) {
    Fo * i = reinterpret_cast<Fo*>(&cls);
    return i->m_i;
}

// double& get_d(Cls& cls) {
//     Fo * d = reinterpret_cast<Fo*>(&cls);
//     return d->m_d;
// }

// int& get_i(Cls& cls) {
//     Fo * i = reinterpret_cast<Fo*>(&cls);
//     return i->m_i;
// }
// struct B {
// B(char c, double d, int i) : c1( c ), d1( d ), i1( i ) {}
// public:
// char c1;
// double d1;
// int i1;
// };

// char &get_c(Cls &cls) {
// void *p = &cls;
// B *pb = static_cast<B*>( p );
// return pb->c1;
// }


int main() 
{
    Cls cls('b', 1.5, (std::int32_t) 3);
    std::cout << get_c(cls);
    return 0;
}
