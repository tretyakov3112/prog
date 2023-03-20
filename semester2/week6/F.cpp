#include <iostream>
using std::cout;
using std::cin;

struct Complex {
    int re;
    int im;
};

Complex complexMul(const Complex& lhs, const Complex& rhs);

void print_complex(const Complex c) {
    cout << c.re << " " << c.im;
}

Complex complexMul(const Complex& lhs, const Complex& rhs) {
    Complex c;
    c.re = lhs.re * rhs.re - lhs.im * rhs.im;
    c.im = lhs.re * rhs.im + lhs.im * rhs.re;
    return c;
}

int main() {
    Complex lhs;
    cin >> lhs.re;
    cin >> lhs.im;
    Complex rhs;
    cin >> rhs.re;
    cin >> rhs.im;
	print_complex(complexMul(lhs, rhs));
}