#include <iostream>
#include <cstring>
using namespace std;

char * resize(const char *buf, size_t size, size_t new_size)
{
    char * ptr = new char[new_size];
    if (new_size >= size) {
        for (int i = 0; i != size; ++i) *(ptr + i) = *(buf + i);
    } else {
        for (int i = 0; i != new_size; ++i) *(ptr + i) = *(buf + i);
    }
    delete[] buf;
    return ptr;
}

int main() {
    int * a = new int[1000];
    for (int i = 0; i != 1000; ++i) a[i] = i;
    char * ptr = resize((const char*) a, 1000, 2000);
    for (int i = 0; i != 2000; ++i) cout << *(ptr+i) << ' ';
}