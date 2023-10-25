#include "iostream"
#include "iomanip"
#include <unistd.h>


int main()
{
    for (int i = 0; i < 101; ++i) {
        std::cout << '\r' << '[' << std::setw(i + 1) << ']' << ' ' << i << "%" << std::setfill('#') << std::right << std::endl;
        sleep(1);
    }
}