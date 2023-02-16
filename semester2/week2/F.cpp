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

int findLastZero(int (&a)[N]){
    int i = N / 2;
    int j = N;
    while (j != 0)
    {
        if (a[i] == 0) {
            i = i + i / 2;
        } else {
            i = i - i / 2;
        }
        j /= 2;
    }
    return i;
}


int main() {
    int a[N];
    read_array(a);
    std::cout << findLastZero(a);
}