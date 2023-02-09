#include <iostream>


int main() {
    int counter_max = 0;
    int counter_min = 0;
    int tmp;
    int N;
    std::cin >> N;
    for (int i = 0; i <= N/2; i++){
        int a;
        int b;
        std::cin >> a;
        if (i > 0){
            std::cin >> b;
            if (a > tmp and a > b){
                counter_max++;
            } else if (a < tmp and a < b){
                counter_min++;
            }
        }
        tmp = a;
    }
    if (counter_max > counter_min){
        std::cout << "MAX" << std::endl;
    } else if (counter_max < counter_min){
        std::cout << "MIN" << std::endl;
    } else {
        std::cout << "EQUAL" << std::endl;
    }
    
       
}