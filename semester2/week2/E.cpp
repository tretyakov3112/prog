#include <iostream>

#ifndef N
#define N 6 // actual size of the array
#endif

void read_array(int (&a)[N]) {
    for (int i = 0; i < N; ++i){
        std::cin >> a[i];
    } 
}

void print_array(int (&c)[2 * N]) {
    for (int i = 0; i < 2 * N; ++i){
        std::cout << c[i] << ' ';
    } 
}

void swap_elements(int (&b)[2 * N], int i, int j) {
    int tmp = b[i];
    b[i] = b[j];
    b[j] = tmp;
}

int max(int a, int b) {
    if (a >= b){
        return a;
    } else {
        return b;
    }
}

void sort(int (&c)[2 * N]) {
    int counter = N;
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0; i < 2 * N; ++i) {
            if (i != 2*N-1)
            {
                if (c[i+1] < c[i])  {
                    ++counter;
                    swap_elements(c, i, i+1);
                }
            }
        }
    }
}

void mergeArrays(int (&a)[N], int (&b)[N], int (&c)[2 * N]) {
    for (int i = 0; i < N; i++)
    {
        c[i] = a[i];
        c[2 * N - i - 1] = b[i]; 
    }
    sort(c);
}



int main() {
    int a[N];
    int b[N];
    int c[2*N];
    read_array(a);
    read_array(b);
    mergeArrays(a, b, c);
    print_array(c);
}