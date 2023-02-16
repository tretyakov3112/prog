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

void swap_elements(int (&b)[N], int i, int j) {
    int tmp = b[i];
    b[i] = b[j];
    b[j] = tmp;
}

void moveNegativeToEnd_withNoOrder(int (&c)[N]) {
    int counter = N;
    while (counter != 0)
    {
        counter = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (c[i] > 0 && i != 0 && c[i-1] < 0)  {
                ++counter;
            }
            if (c[i] > 0 && i != 0)  {
                swap_elements(c, i, i-1);
            }
        }
    }
}

void movePositiveToBeginning_withNoOrder(int (&b)[N]) {
    int counter = N;
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0; i < N; ++i) {
            if (b[i] < 0 && i != N-1 && b[i+1] > 0)  {
                ++counter;
            }
            if (b[i] < 0 && i != N-1)  {
                swap_elements(b, i, i+1);
            }
        }
    }
}

void moveNegativeToEnd(int (&a)[N]) {
    int b[N];
    int c[N];
    for (int i = 0; i < N; ++i){
        b[i] = c[i] =  a[i];
    }
    movePositiveToBeginning_withNoOrder(b);
    moveNegativeToEnd_withNoOrder(c);
    for (int i = 0; i < N; i++)
    {
        if (b[i] > 0) {
            a[i] = b[i];
        }
        if (c[i] < 0) {
            a[i] = c[i];
        }
    }
}



int main() {
    int a[N];
    read_array(a);
    moveNegativeToEnd(a);
    print_array(a);
}