#include <iostream>

int main() {
    int a, b, c;
    int const D = b*b - 4*a*c;
    if (a != 0){
        std::cout << (-b+D)/(2*a) << " " << (-b-D)/(2*a) << std::endl;
    } else if (b != 0){
        std::cout << -c/b << std::endl;
    } else if (c == 0){
        std::cout << "any solution" << std::endl;
    } else {
        std::cout << "no solution" << std::endl;
    }
}