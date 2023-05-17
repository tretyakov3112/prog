#include <iostream>
using namespace std;

int main() {
    int L, count = 0;
    cin >> L;
    for (int d100 = 0; d100 <= 9; d100++) {
        for (int dd100 = 0; dd100 <= 9; dd100++) {
            for (int d10 = 0; d10 <= 9; d10++) {
                int result;
                if ((min(d100, dd100) != 0 && min(d100 * 10, dd100 * 10) <= L)) {
                    result = min(d100 * 10, dd100 * 10);
                } else result = max(d100, dd100) * 10;
                result += d10;
                if (result > L || result == 0) continue;
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
// if(max(d100 * 10, dd100 * 10) <= L && d100 == 0 && dd100 == 0) result = max(d100 * 10, dd100 * 10);
//                 else 