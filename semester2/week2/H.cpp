#include <iostream>

#ifndef N
#define N 2 
#endif
#ifndef M
#define M 3 
#endif

void read_array(int (&a)[N][M]) {
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; j++)
        {
            std::cin >> a[i][j];
        }
    } 
}

void print_array(int (&a)[N][M]) {
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; j++)
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    } 
}


void print_transposed(int (&array)[N][M]) {

    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; j++)
        {
            std::cout << array[j][i] << ' ';
        }
        std::cout << '\n';
    } 
    
}

int main() {
    int a[N][M];
    read_array(a);
    print_transposed(a);
}