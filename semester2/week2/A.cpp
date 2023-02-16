#include <iostream>

#ifndef N
#define N 10 // actual size of the array
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

void reverseArray(int (&a)[N]) {
    int tmp[N];
    for (int i = 0; i < N; ++i){
        tmp[i] =  a[i];
    } 
    for (int i = N; i > 0; i--){
        a[N - i] =  tmp[i-1];
    } 
}

int main() {
    int a[N];
    read_array(a);
    reverseArray(a);
    print_array(a);
}