#include <iostream>

int is_pol(int N) {
    int tmp = 0;
    int k = N;
    while (k != 0){
        tmp = 10 * tmp + k % 10;
        k /= 10;
    }
    if (tmp == N){
        return 1;
    }else {
        return 0;
    }    
}

int main() {
    int a;
    std::cin >> a;
    if (is_pol(a) == 1){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }    
}