#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using std::cout;
using std::cin;
using std::endl;

void find_two(int* array, int s, int a) {
    for (int i = 0; i < a; i++) {
        for (int j = i+1; j < a; j++) {
            if (array[i]+array[j] == s) {
                return;
            }
        }
    }
} 

int main(){
    double t1 = 0;
    unsigned seed = 1001;
    int s_count = 100;
    for (int m = 100; m<2100; m += 100){
        int* array = new int[m];
        for (int i = 0; i < m; i++){
            array[i] = i;
        } 
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, 3*m);
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < s_count; j++){
            find_two(array, dstr(rng), m); 
        }
        auto end = std::chrono::steady_clock::now();
        auto time_s = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        t1 = time_s.count();
        std::cout << t1/s_count << std::endl;
        delete [] array;
    }

    return 0;
}
