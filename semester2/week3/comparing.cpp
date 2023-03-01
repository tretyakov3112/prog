#include <iostream>
#include <chrono>
#include <random>

unsigned seed = 972;
std::default_random_engine rng(seed);

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

void selectSort(int (&a)[], int N) {
    for (int i = 0; i < N - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < N; j++) {
            if (a[j] < a[min_ind]) min_ind = j;
        }
        if (min_ind != i) std::swap(a[i], a[min_ind]);
    }
}

void doubleSelectSort(int (&a)[], int N) {
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

int time_measure(int (&a)[], int multiplier, int N) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 1; i < multiplier; i++) doubleSelectSort(a, N);
        auto end = std::chrono::steady_clock::now();
        auto time_span = 
        std::chrono::duration_cast <std::chrono::milliseconds>(end - begin);
        sum += time_span.count();
    }
    return sum / 5;
    
}


int main() {
    // int counter = 9;
    for (int N = 512; N < 100000; N*=2)
    {
        int a[N] = {0};
        rand_list(a, N);
        std::cout << time_measure(a, 20, N) << '\n';  
    }
    
    return 0;
}