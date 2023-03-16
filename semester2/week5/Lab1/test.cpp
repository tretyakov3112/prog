#include <iostream>
#include <chrono>
#include <fstream>
#include <random>



void randomize(int* ptr, int N, int seed) {
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N);
    for (int i = 0; i != N; ++i) *(ptr + i) = dstr(rng);
}

int main() {
    int seed = 1001;
    int m = 100;
    int* ptr = new int[m];
    randomize (ptr, m, seed);
    // int f = rand();
    // std::default_random_engine rng(seed);
    // std::uniform_int_distribution<unsigned> dstr(0, m);
    // auto begin = std::chrono::steady_clock::now();
    // for (int j = 0; j < s_count; j++){
    //     binar_search(a, f, m); 
    // }
    // auto end = std::chrono::steady_clock::now();
    // auto time_s = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // t1 = time_s.count();
    // std::cout << t1/s_count << std::endl;
    // delete [] a;
    for (int j = 0; j < m; j++) std::cout << ptr[j] << ' ';

    return 0;
}