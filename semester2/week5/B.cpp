#include <iostream>
using namespace std;

int main() {
    short int * ptr;
    ptr = new short int[10];
    for (short int i = 0; i != 10; ++i) ptr[i] = i;
    for (short int i = 0; i != 10; ++i) cout << ptr+i << ' ' << *(ptr+i);
    cout << '\n' << endl;
    for (short int i = 0; i != 10; ++i) cout << *(ptr+i) << ' ';
    for (short int i = 0; i != 10; i+=2) *(ptr+i) = i*i;
    cout << '\n' << endl;
    for (short int i = 0; i != 10; ++i) cout << *(ptr+i) << ' ';

    return 0;
}