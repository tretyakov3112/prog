#include <iostream>

int zeros_in_tail(int N) {
    int k = N;
    if (N % 10 >= 5){
        k = 2 * (N / 10) + 1;
    } else {
        k = 2 * (N / 10);
    }
    return k;
}

int main() {
    int a;
    std::cin >> a;
    std::cout << zeros_in_tail(a) << std::endl; 
}