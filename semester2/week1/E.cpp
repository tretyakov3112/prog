#include <iostream>

int recursive_power(int base, int power) {
    if (power == 0){
        return 1;
    } else {
        while (power != 0){
        --power;
        return base * recursive_power(base, power);
        }
    }  
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << recursive_power(a, b)<< std::endl;   
}

