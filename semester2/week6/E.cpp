#include <iostream>
using std::cout;
using std::cin;

struct vectorN {
    int dim;
    int* x;
};

void print_vector(vectorN vec) {
    cout << vec.dim << ' ';
    for (int i = 0; i != vec.dim; ++i) cout << vec.x[i] << ' ';
}

vectorN plus(vectorN vec1, vectorN vec2) {
    vectorN res;
    res.dim = vec1.dim;
    res.x = new int[res.dim];
    for (int i = 0; i != vec1.dim; ++i) res.x[i] = vec1.x[i] + vec2.x[i];
    return res; 
}

int main() {
    vectorN vec1;
    cin >> vec1.dim;
    vec1.x = new int[vec1.dim];
    for (int i = 0; i != vec1.dim; ++i) cin >> vec1.x[i];
	vectorN vec2;
    vec2.dim = vec1.dim;
    vec2.x = new int[vec2.dim];
    for (int i = 0; i != vec2.dim; ++i) cin >> vec2.x[i];
	print_vector(plus(vec1, vec2));
}