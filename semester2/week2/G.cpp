#include <iostream>

#ifndef N
#define N 7 // actual size of the array
#endif

void read_array(int (&array)[N]) {
    for (int i = 0; i < N; ++i){
        std::cin >> array[i];
    } 
}

int findUnique(int (&array)[N]) {
    int res = 0;
    for (auto &elem : array) res ^= elem;
    return res;
}

int main() {
    int array[N];
    read_array(array);
    std::cout << findUnique(array);
}