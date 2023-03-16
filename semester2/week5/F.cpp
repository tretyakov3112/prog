#include <iostream>
#include <cstring>
using namespace std;


// В этой задаче вам нужно реализовать функцию resize. Функция resize принимает на вход три аргумента: указатель на область памяти, 
// выделенную с помощью оператора new[], размер области (size) и новый размер (new_size). 
// Функция должна выделить память размера new_size, скопировать в нее данные из переданной области памяти, 
// освободить старую область памяти и вернуть выделенную область памяти нового размера со скопированными данными.

// Обратите внимание, что память, возвращенная из функции, будет освобождена с помощью оператора delete[]. 
// Несмотря на то, что входной тип данных — это const char *, не стоит рассчитывать, что там хранится только тип char. 
// При выполнении задания также учтите, что new_size может быть меньше size.

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