#include<iostream>

template<int base, int pow>
struct power
{
    static const int value = base * power<base, pow - 1>::value;
    
};

template<int base>
struct power<base, 0>
{
    static const int value = 1;
};

int main()
{
    std::cout << power<3, 4>::value << std::endl;
}