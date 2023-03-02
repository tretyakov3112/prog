#include <iostream>

#ifndef N
#define N 6 // actual size of the array
#endif

void bubble_with_step(int (&a)[N], int step) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j+=step) {
            if (a[j] < a[i]) std::swap(a[i], a[j]);
        }
    }
}

void combSort(int (&a)[N], int step) {
    bubble_with_step(a, step);
    bubble_with_step(a, 1);
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) std::cin >> a[i];
    combSort(a, 2);
    for (int i = 0; i < N; i++) std::cout << a[i] << " ";
}