#include <iostream>
#include <cmath>

int main() {
    int p = 45932;
    for (int i = 2; i <= (int) sqrt(p); i++){
        if (p % i == 0){
            std::cout << "not a prime" << std::endl;
            break;
        } else if (i == (int) sqrt(p)){
            std::cout << "prime" << std::endl;
        }
    }
}