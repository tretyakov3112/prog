#include <iostream>
#include <chrono>
#include <random>

void bubble_with_step(int (&a)[], int step, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j+=step) {
            if (a[j] < a[i]) std::swap(a[i], a[j]);
        }
    }
}

void combSort(int (&a)[], int step, int N) {
    bubble_with_step(a, step, N);
    bubble_with_step(a, 1, N);
}

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


int time_measure(int (&a)[], int multiplier, int N) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 1; i < multiplier; i++) combSort(a, 4, N);
        auto end = std::chrono::steady_clock::now();
        auto time_span = 
        std::chrono::duration_cast <std::chrono::milliseconds>(end - begin);
        sum += time_span.count();
    }
    return sum / 5;
    
}


int main() {
    for (int N = 100; N < 9700; N+=100)
    {
        int a[N] = {0};
        rand_list(a, N);
        std::cout << time_measure(a, 10, N) << '\n';  
    }
    
    return 0;
}