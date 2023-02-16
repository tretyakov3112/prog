#include <iostream>

int zeros_in_tail(int N) {
    int k = 5;
    int new_number = 0;
    while(k < N){
        new_number += N / k;
        k *= 5;
    }
    return new_number;
}

int main() {
    int a;
    std::cin >> a;
    std::cout << zeros_in_tail(a) << std::endl; 
}