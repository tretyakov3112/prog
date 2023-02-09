#include <iostream>

int my_power(int base, int power) {
    int new_numb = 1;
    if (power == 0){
        return 1;
    } else {
        int k = power;
        while (k != 0){
        --k;
        new_numb *= base;
        }
    } 
    return new_numb; 
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << my_power(a, b)<< std::endl;   
}
