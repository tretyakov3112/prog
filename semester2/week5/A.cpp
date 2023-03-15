#include <iostream>
using namespace std;

int main() {
    double* ptr;
    double a = 0;
    ptr = &a;
    cout << ptr << '\n' << *ptr << endl;
    ptr -= 3;
    cout << ptr << '\n' << *ptr << endl;
    ptr += 5;
    cout << ptr << '\n' << *ptr << endl;

    return 0;
}
