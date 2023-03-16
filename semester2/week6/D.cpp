#include <iostream>
using std::cout;
using std::cin;
using std::min;
using std::max;

struct vector2d {
    double* x;
};

void print_vector (vector2d vec) {
    for (int i = 0; i != 2; ++i) cout << vec.x[i] << ' ';
}

vector2d plus (vector2d vec1, vector2d vec2) {
    vector2d res;
    res.x = new double[2];
    for (int i = 0; i != 2; ++i) res.x[i] = vec1.x[i] + vec2.x[i];
    return res; 
}

vector2d opposite(vector2d vec) {
    vector2d res;
    res.x = new double[2];
    for (int i = 0; i != 2; ++i) res.x[i] = -vec.x[i];
    return res; 
}

double cross_product(vector2d vec1, vector2d vec2) {
    return vec1.x[1] * vec2.x[2] - vec1.x[2] * vec2.x[1]; 
}

struct Street {
    vector2d begin;
    vector2d end;
};

bool isParallel (Street street1, Street street2) {
    if ((street1.end.x[2] - street1.begin.x[2]) * (street2.end.x[1] - street2.begin.x[1]) == 
    (street2.end.x[2] - street2.begin.x[2]) * (street1.end.x[1] - street1.begin.x[1])) return true;
}

bool isIntersection (Street street1, Street street2) {
    if (isParallel(street1, street2)) {
        Street tmp;
        tmp.begin = street1.begin;
        tmp.end = street2.end;
        if (!isParallel(tmp, street1) or
        max(street1.begin.x[1], street1.end.x[1]) < min(street2.begin.x[1], street2.end.x[1]) or 
        min(street1.begin.x[1], street1.end.x[1]) > max(street2.begin.x[1], street2.end.x[1])) return false;
        return true;
    }
    vector2d tmp1 = plus(street2.end, opposite(street1.begin));
    vector2d tmp2 = plus(street2.begin, opposite(street1.begin));
    vector2d tmp3 = plus(street1.end, opposite(street2.begin));
    vector2d tmp4 = plus(street2.begin, opposite(street2.begin));
    vector2d vstreet1 = plus(street1.end, opposite(street1.begin));
    vector2d vstreet2 = plus(street2.end, opposite(street2.begin));
    if (cross_product(vstreet1, tmp1) * cross_product(vstreet1, tmp2) <= 0 and 
    cross_product(vstreet2, tmp3) * cross_product(vstreet2, tmp4) <= 0) return true;
    return false;
}

int main() {
    Street street1;
    Street street2;
    street1.begin.x = new double[2];
    street1.end.x = new double[2];
    street2.begin.x = new double[2];
    street2.end.x = new double[2];
	for (int i = 0; i != 2; ++i) cin >> street1.begin.x[i];
    for (int i = 0; i != 2; ++i) cin >> street1.end.x[i];
    for (int i = 0; i != 2; ++i) cin >> street2.begin.x[i];
    for (int i = 0; i != 2; ++i) cin >> street2.end.x[i];
	if (isIntersection(street1, street2)) cout << "NO";
    else cout << "YES";
}