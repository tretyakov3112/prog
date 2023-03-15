#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

void binar_search(int* array, int k, int array_size) {
    int l = 0;
    int r = array_size - 1;
    int m = 0;
    while (l < r) {
        m = (l + r)/2;
        if (k == array[m]) {
            return;
        }
        if (k < array[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
} 


int main() {
    double t1 = 0;
    unsigned seed = 1001;
    int s_count = 100000;
    for (int m = 100; m<1000100; m += 50000){
        int* a = new int[m];
        for (int i = 0; i < m; i++){
            a[i] = i;
        } 
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, m);
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < s_count; j++){
            binar_search(a, -1, m); 
        }
        auto end = std::chrono::steady_clock::now();
        auto time_s = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        t1 = time_s.count();
        std::cout << t1/s_count << std::endl;
        delete [] a;
    }

    return 0;
}
