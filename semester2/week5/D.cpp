#include <iostream>
using namespace std;

void input_array(int* ptr, size_t N);
void reverse(int* ptr, size_t N);
void print(const int* ptr, size_t N);

void input_array(int* ptr, size_t N) {
    for (int i = 0; i < N; i++) cin >> ptr[i];
}

void reverse(int* ptr, size_t N) {
    for (int i = 0; i < N/2; i++) swap(ptr[i], ptr[N-i-1]);
}

void print(int* ptr, size_t N) {
    for (int i = 0; i < N; i++) cout << ptr[i] << ' ';
}

int main() {
    size_t N = 0;
    int* ptr = nullptr;
    cin >> N;
    ptr = new int[N];
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
    return 0;
}