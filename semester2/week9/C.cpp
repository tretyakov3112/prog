#include <iostream>


int count_money(int M, int k, int a[]) {
    int counter = 0;
    for (int i = k - 1; i >= 0; i--) {
        if (M >= a[i]) {
            counter += M / a[i];
            M = M % a[i];
        } 
    }
    
    return counter;
}

int main() {
    int k, M;
    std::cin >> k;
    int a[k];
    for (int i = 0; i < k; i++) std::cin >> a[i];
    std::cin >> M;
    std::cout << count_money(M, k, a) << std::endl;
    return 0;
}