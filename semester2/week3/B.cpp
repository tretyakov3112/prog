#include <iostream>

#ifndef N
#define N 6 // actual size of the array
#endif

void doubleSelectSort(int (&a)[N]) {
    for (int i = 0; i < N; i++)
    {
        int min_ind = i;
        int max_ind = N - i - 1;
        for (int j = i; j < N - i; j++)
        {
            if (a[j] < a[min_ind]) min_ind = j;
            if (a[j] > a[max_ind]) max_ind = j; 
        }
        if (min_ind != i) {
          std::swap(a[i], a[min_ind]);
          if (i == max_ind) max_ind = min_ind;
        }
        if (max_ind != N - i - 1) std::swap(a[N - i - 1], a[max_ind]);
        if (max_ind <= min_ind) break;
    }
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) std::cin >> a[i];
    doubleSelectSort(a);
    for (int i = 0; i < N; i++) std::cout << a[i] << " ";
}