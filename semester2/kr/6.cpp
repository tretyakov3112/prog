#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l;
    std::cin >> n;
    int min_num_wag = n;
    std::vector<int> wag(n);
    std::vector<int> sum_sum(n+1);
    for (int i = 0; i < n; ++i) {
        std::cin >> wag[i];
        sum_sum[i+1] = sum_sum[i] + wag[i];
    }

    std::cin >> l;

    for (int i = 0; i < n; i++) {
        int sum_i_j = 0;
        for (int j = i; j < n; j++){
            sum_i_j += wag[j];
            if (sum_i_j >= l) {
                min_num_wag = std::min(min_num_wag, j - i + 1);
                break;
            }
        }
    }
    std::cout << min_num_wag << std::endl;
    return 0;
}