#include<iostream>

template<typename T>
class S
{

};

template<typename T>
class S<T, int>
{

};

template<>
vector<bool>
{
    char *
}

template<typename T, typename U>
foo(T& t, U& u)
{

}

std::is_same<T,U>::value

template<typename T, ... U>
struct is_same
{
    static const bool value = false; // static const == constexpr
};

template<typename T>
struct is_same<T, T>
{
    static const bool value = true;
};

type_traits

template<unsigned N>
struct fact
{
    static const unsigned value = N*fact<N-1>::value;
};

template<>
struct fact<0>
{
    static const unsigned value = 1;
};
