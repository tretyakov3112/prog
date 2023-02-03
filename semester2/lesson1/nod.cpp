#include <iostream>

int main() {
    int a = 204;
    int r = 45932;
    int c;
    while(a != 0){
        c = a;
        a = r % a;
        r = c;
    }
    std::cout << r << std::endl;
}