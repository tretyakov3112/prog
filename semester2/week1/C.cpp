#include <iostream>

int is_visokosnii(int N) {
    if (N % 4 == 0 and N % 100 != 0 or N % 400 == 0){
        return 1;
    }else {
        return 0;
    }    
}

int main() {
    int a;
    std::cin >> a;
    if (is_visokosnii(a) == 1){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }    
}