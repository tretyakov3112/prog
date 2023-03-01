#include <iostream>

#ifndef N
#define N 6 // actual size of the array
#endif

void flip(int (&a)[N], int n) {
	for (int i = 0; i < n; i++) {
		--n;
		std::swap(a[i], a[n]);
	}
}

void pancakeSort(int (&a)[N]) {
	for (int i = N - 1; i >= 0; --i)
	{
		int pos = i;
		for (int j = 0; j < i; j++) {
			if (a[j] > a[pos]) pos = j;
		}

		if (pos == i) continue;
		if (pos != 0) flip(a, pos + 1);
		flip(a, i + 1);
	}
}


int main() {
    int a[N];
    for (int i = 0; i < N; i++) std::cin >> a[i];
    pancakeSort(a);
    for (int i = 0; i < N; i++) std::cout << a[i] << " ";
}