
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> lengths(n-1);
    for (int i = 0; i < n-1; i++) {
        lengths[i] = a[i+1] - a[i];
    }
    if (n == 2) {
        cout << lengths[0];
    } else {
        int total = lengths[0];
        
        for (int i = 2; i < n-2; i++) {
            lenghts[i] = min(lenghts[i - 1],lenghts[i - 2]) + a[i] - a[i - 1];
            // if (lengths[i] >= lengths[i+1]) { 
            //     total += lengths[i+1];
            //     continue;
            // } else {
            //     total += lengths[i];
            // }
            // if (i == n-5 || i == n-4) {
            //     if (lengths[n-3] >= lengths[n-4]) {
            //         total += lengths[n-4];
            //     } else {
            //         total += lengths[n-3];
            //     }
            // }
        }
        cout << total;
    }
    
    return 0;
} 