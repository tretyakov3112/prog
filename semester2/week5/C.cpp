#include <iostream>
using namespace std;

int main() {
    int x = 1;
    int i = 0;
    int * ptr;
    while (x != 0) {
        cin >> x;
        *(ptr + i) = x;
        ++i;
    }
    int m[i-1];
    for (int j = 0; j != i - 1; j++) m[j] = *(ptr + j);
    if (i >= 2) for (int j = 0; j != i - 2; j++) cout << -m[j+1] + m[j] << ' ';

    return 0;
}