#include <iostream>
using namespace std;

bool reserve_memory(int* ptr, size_t N);
void free_memory(int* ptr);

bool reserve_memory(int* dst, size_t N) {
    if (dst != nullptr) return false;
    int* ptr = new int[N];
    if (ptr != nullptr) return true;
    else return false;
}

void free_memory(int* ptr) {
    delete[] ptr;
}

int main() {
    size_t N = 0;
    int* ptr = nullptr;
    cin >> N;
    cout << reserve_memory(ptr, N) << endl;
    free_memory(ptr);
    return 0;
}