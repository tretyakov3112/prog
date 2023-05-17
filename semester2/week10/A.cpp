#include <iostream>
using namespace std;

unsigned long long fibo(unsigned long long f[], int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 4;
    for (int i = 3; i <= n; i++) f[i % 3] = 2*f[(i - 1) % 3] + 2*f[(i - 2) % 3] - f[i % 3];
    return f[n % 3];
}

int main() {
    unsigned long long n;
    unsigned long long f[3] = {1, 1, 4};
    cin >> n;
    cout << fibo(f, n);
    return 0;
}