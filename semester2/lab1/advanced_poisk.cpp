#include <iostream>
#include <chrono>
#include <random>

unsigned seed = 972;
std::default_random_engine rng(seed);

int random_number_in_array(int a[], int n, int N) {
    std::uniform_int_distribution<unsigned> dstr(n , N);
    return a[dstr(rng)];
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

int advanced_search_A(int (&a)[], int number, int N) {
    for (int i = 0; i < N; i++)
    {
        if (a[i] == number) {
            std::swap(a[i], a[0]);
            return i;
        } else if (a[i] != number && i == N - 1) {
            return -1;
        }
    } 
}

int advanced_search_B(int (&a)[], int number, int N) {
    for (int i = 0; i < N; i++)
    {
        if (a[i] == number) {
            if (i != 0) std::swap(a[i], a[i-1]);
            return i;
        } else if (a[i] != number && i == N - 1) {
            return -1;
        }
    } 
}

int advanced_search_C(int (&a)[], int number, int N) {
    int counter_list[N] = {0};
    for (int i = 0; i < N; i++)
    {
        if (a[i] == number) {
            ++counter_list[i];
            if (i != 0 && counter_list[i] > counter_list[i-1]) std::swap(a[i], a[i-1]);
            return i;
        } else if (a[i] != number && i == N - 1) {
            return -1;
        }
    } 
}



int time_measure(int (&a)[], int number, int multiplier, int N) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 1; i < multiplier; i++) advanced_search_C(a, number, N);
        auto end = std::chrono::steady_clock::now();
        auto time_span = 
        std::chrono::duration_cast <std::chrono::milliseconds>(end - begin);
        sum += time_span.count();
    }
    return sum / 5;
    
}


int main() {
    // int counter = 9;
    for (int N = 512; N < 500000; N*=2)
    {
        int a[N];
        for (int i = 0; i < N; i++)
        {
            a[i] = i;
        }
        
        int t = 0;
        for (int j = 0; j < 10; j++)
        {
            int number = random_number_in_array(a, N-3, N);
            t+=time_measure(a, number, 1000, N);
        }
        t/=10;
        
        std::cout <<  t << '\n';  
    }
    
    return 0;
}