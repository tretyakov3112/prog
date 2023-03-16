#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    string name;
    int mark;
};

int average_mark(Student* students, int N){
    int sum = 0;
    for (int i = 0; i != N; ++i) sum += students[i].mark;
    return sum / N;
}

int main() {
	int N;
	cin >> N;
    Student* students = new Student[N];
    for (int i = 0; i != N; ++i) {
        cin >> students[i].name;
        cin >> students[i].mark;
    }
	cout << average_mark(students, N);
}