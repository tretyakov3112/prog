#include <iostream>
#include <chrono>
#include <random>

unsigned seed = 972;
std::default_random_engine rng(seed);

int random_number_in_array(int a[], int N) {
    std::uniform_int_distribution<unsigned> dstr(0 , N);
    return a[dstr(rng)];
}

int random_number(int N) {
    std::uniform_int_distribution<unsigned> dstr(0 , N);
    return dstr(rng);
}



int find_sum(int a[], int k, int N) {
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if (a[i] + a[j] == k) {
                return 1;
            }
        }
        
    }
    return -1;
    
}

int lin_sum(int a[], int number, int N){
    int left = 0; // a[left] <= number && a[right] > number
    int right = N - 1;
    while (a[left] + a[right] != number)
    {
        if (a[left] + a[right-1] < number && a[left+1] + a[right] > number) {
            return -1;
        } 
        if (a[left] + a[right] > number) {
            --right;
        } else {
            ++left;
        } 
        
    }
    return left + right;
}

int time_measure(int a[], int number, int multiplier, int N) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 1; i < multiplier; i++) lin_sum(a, number, N);
        auto end = std::chrono::steady_clock::now();
        auto time_span = 
        std::chrono::duration_cast <std::chrono::milliseconds>(end - begin);
        sum += time_span.count();
    }
    return sum / 5;
    
}


int main() {
    // int counter = 9;
    for (int N = 512; N < 2000000; N*=2)
    {
        int a[N];
        for (int i = 0; i < N; i++)
        {
            a[i] = i;
        }
        int number = random_number(2*N);
        std::cout << time_measure(a, number, 1000, N) << '\n';  
        // std::cout << lin_sum(a, -1, N) << '\n'; 
    
    }
    
    return 0;
}