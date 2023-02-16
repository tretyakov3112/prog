#include <iostream>

#ifndef N
#define N 6 // actual size of the array
#endif

void read_array(int (&a)[N]) {
    for (int i = 0; i < N; ++i){
        std::cin >> a[i];
    } 
}

void print_array(int (&a)[N]) {
    for (int i = 0; i < N; ++i){
        std::cout << a[i] << ' ';
    } 
}

void shiftRight(int (&a)[N]) {
    int tmp[N];
    for (int i = 0; i < N; ++i){
        tmp[i] =  a[i];
    } 
    a[0] = tmp[N-1];
    for (int i = 1; i < N; ++i){
        a[i] =  tmp[i-1];
    } 
}

int main() {
    int a[N];
    read_array(a);
    shiftRight(a);
    print_array(a);
}