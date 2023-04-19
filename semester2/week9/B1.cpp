#include <iostream>
using namespace std;


int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}


void egypt(int M, int N){
   while(M != 1){
        int i = N / M + 1; 
        cout << i << ' ';
        M = -N % M + M;
        N *= i;
        int nod = gcd(M, N);
        N /= nod;
        M /= nod;
    }
    cout << N;
}

int main(){
    int M, N;
    cin >> M >> N;
    egypt(M, N);
}