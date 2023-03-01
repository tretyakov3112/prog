#include <iostream>

#ifndef N
#define N 6 // actual size of the array
#endif

void selectSort(int (&a)[N]) {
    for (int i = 0; i < N - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < N; j++) {
            if (a[j] < a[min_ind]) min_ind = j;
        }
        if (min_ind != i) std::swap(a[i], a[min_ind]);
    }
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) std::cin >> a[i];
    selectSort(a);
    for (int i = 0; i < N; i++) std::cout << a[i] << " ";
}