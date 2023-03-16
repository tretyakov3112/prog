#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
#include <algorithm>

void randomize(int* ptr, int N, int seed) {
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N);
    for (int i = 0; i != N; ++i) *(ptr + i) = dstr(rng);
}

int binar_search(int* array, int k, int a) {
    int l = 0;
    int r = a - 1;
    int m = 0;
    while (l < r) {
        m = (l + r)/2;
        if (k == array[m]) {
            return m;
        }
        if (k < array[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
} 

void create_outfile(double* ptr, size_t N, int step) {
    std::ofstream out("data.txt", std::ios::out);
    for (int i = 0; i < N; ++i) {
        if (out.is_open()) {
            out << step * (i + 1) << " " << ptr[i] << std::endl;
        }
    }
    out.close();
}


int main() {
    double* t1 = new double[20];
    unsigned seed = 1001;
    int s_count = 100000;
    int step = 50000;
    for (int m = 100; m<1000100; m += step){
        int* a = new int[m];
        randomize (a, m, seed);
        std::sort(a, (a + m - 1));
        int f = rand();
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < s_count; j++){
            binar_search(a, f, m); 
        }
        auto end = std::chrono::steady_clock::now();
        auto time_s = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        t1[m/step] = time_s.count() / s_count;
        std::cout << t1[m/step] << std::endl;
        delete [] a;
    }
    create_outfile(t1, 20, step);

    return 0;
}