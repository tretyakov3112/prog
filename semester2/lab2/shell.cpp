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

void selectSort_with_step(int (&a)[], int step, int N) {
    for (int i = 0; i < N - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < N; j+=step) {
            if (a[j] < a[min_ind]) min_ind = j;
        }
        if (min_ind != i) std::swap(a[i], a[min_ind]);
    }
}

void shellSort1(int (&a)[], int N) {
    for (int i = N; i > 0; i/=2){
        selectSort_with_step(a, i, N);
    }
}

void shellSort2(int (&a)[], int N) {
    int i = 0;
    while (pow(2, i) - 1 < N) i++;
    
    for (; i > 1; i--){
        selectSort_with_step(a, pow(2, i-1) - 1, N);
    }
}

int fibonacci(unsigned i) {
    if (i == 0){
        return 0;
    } else if (i == 1){
        return 1;
    } else {
        return fibonacci(i-1)+fibonacci(i-2);
    }
}

void shellSort3(int (&a)[], int N) {
    int i = 0;
    while (fibonacci(i) < N) i++;
    
    for (; i > 1; i--){
        selectSort_with_step(a, fibonacci(i-1), N);
    }
}

int time_measure(int (&a)[], int multiplier, int N) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 1; i < multiplier; i++) shellSort3(a, N);
        auto end = std::chrono::steady_clock::now();
        auto time_span = 
        std::chrono::duration_cast <std::chrono::milliseconds>(end - begin);
        sum += time_span.count();
    }
    return sum / 5;
    
}


int main() {
    for (int N = 300; N < 9300; N+=100){
        int a[N] = {0};
        rand_list(a, N);
        std::cout << time_measure(a, 10, N) << '\n';  
    }
    return 0;
}