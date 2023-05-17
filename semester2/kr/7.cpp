#include <iostream>
#include <vector>
#include <algorithm>


using std::cin;
using std::cout;

int main() {
    int n;
    cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int ans = 0;
    int p, l;
    cin >> p >> l;
    for (int i = 0; i < n; ++i) {
        int cnt = p / a[i];
        cnt = std::min(cnt, l);
        if (cnt == 0) {
            break;
        }
        p -= cnt * a[i];
        ans += cnt;
    }
    cout << ans;
}