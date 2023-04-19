#include <iostream>


int count_money(int M) {
    int counter = 0;
    if (M >= 98) {
        counter += M / 98;
        M = M % 98;
    } 
    if (M >= 63) {
        counter += M / 63;
        M = M % 63;
    }
    if (M >= 49) {
        counter += M / 49;
        M = M % 49;
    }
    if (M >= 28) {
        counter += M / 28;
        M = M % 28;
    }
    if (M >= 7) {
        counter += M / 7;
        M = M % 7   ;
    }
    if (M >= 1) counter += M;
    return counter;
}

int main() {
    int M;
    std::cin >> M;
    std::cout << count_money(M) << std::endl;
    return 0;
}