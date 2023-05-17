#include <iostream>
using namespace std;

int main() {
    int N, k, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> k;
        int power = 1;
        while (k != 0) {
            sum += (k % 10) * power;
            k /= 10;
            power *= 7;
        }
    }
    int new_sum = 0, power2 = 1;
    while (sum != 0) {
        new_sum += (sum % 4) * power2;
        sum /= 4;
        power2 *= 10;
    }
    cout << new_sum;
    return 0;
}