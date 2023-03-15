#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

void linear_search(int* array, int k, int a){
    for (int i = 0; i < a; i++){
        if (k == array[i]){
            return;
        }
    }
}

int main() {
    double t1 = 0;
    unsigned seed = 1001;
    int s_count = 100000;
    for (int m = 100; m<2100; m += 100){
        int* a = new int[m];
        for (int i = 0; i < m; i++){
            a[i] = i;
        } 
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, m);
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < s_count; j++){
            linear_search(a, -1, m); 
        }
        auto end = std::chrono::steady_clock::now();
        auto time_s = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        t1 = time_s.count();
        std::cout << t1/s_count << std::endl;
        delete [] a;
    }

    return 0;
}
