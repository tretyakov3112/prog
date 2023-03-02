#include <iostream>
#include <random>
#include <algorithm>

// #ifndef N
// #define N 100 // actual size of the array
// #endif

unsigned seed = 972;
std::default_random_engine rng(seed);

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


int random_number_in_array(int a[], int N) {
    std::uniform_int_distribution<unsigned> dstr(0 , N);
    return a[dstr(rng)];
}

int random_number(int N) {
    std::uniform_int_distribution<unsigned> dstr(0 , N);
    return dstr(rng);
}

void rand_list(int (&a)[], int N) {
    for (int i = 0; i < N; i++)
    {
        a[i] = random_number(N);
    }
    
}




int main() {
    int N = 10;
    int a[N] = {3, 2, 4, 6, 1, 0, 4, 7, 9, 5};
    rand_list(a, N);
    for (int i = 0; i < N; i++) {
        int number = random_number(2*i);
        std::cout << number << ' ' << lin_sum(a, number, N) << " - "; 
        for (int j = 0; j < N; j++) {
            std::cout << a[j] << ' ';
            if (j == N-1) std::cout << '\n';
        }
    } 
    return 0;
}