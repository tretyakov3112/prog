#include<iostream>

template<unsigned N>
struct is_prime
{
    static const bool value = false;
    unsigned i = 2;
    unsigned tmp;
    while (i != N)
    {
        tmp = 0;
        while (N > tmp) tmp += i;
        if (tmp == N) break; 
        if (i == N-1) value = true;
        i++;
    }
};

template<>
struct is_prime<1>
{
    static const bool value = false;
};

template<>
struct is_prime<2>
{
    static const bool value = true;
};

int main()
{
    std::cout << is_prime<71>::value << std::endl;
}