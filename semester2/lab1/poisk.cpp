#include <iostream>
#include <chrono>
#include <random>

unsigned seed = 972;
std::default_random_engine rng(seed);

int random_number_in_array(int a[], int N) {
    std::uniform_int_distribution<unsigned> dstr(0 , N);
    return a[dstr(rng)];
}


int bin_search(int a[], int number, int N){
    int left = -1; // a[left] <= number && a[right] > number
    int right = N - 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (a[mid] <= number) {
            left = mid;
        } else {
            right = mid;
        } 
    }
    if (left > -1 && a[left] == number) {
        return left;
    } else {
        return -1;
    }
}

int lin_search(int a[], int number, int N) {
    for (int i = 0; i < N; i++)
    {
        if (a[i] == number) {
            return i;
        } else if (a[i] != number && i == N - 1) {
            return -1;
        }
    }
    
}

void func() {
    std::cout << "Hello" << '\n';
}

int time_measure(int a[], int number, int multiplier, int N) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 1; i < multiplier; i++) bin_search(a, number, N);
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
        int number = random_number_in_array(a, N);
        std::cout << time_measure(a, number, 1000000, N) << '\n';  
    
    }
    
    return 0;
}