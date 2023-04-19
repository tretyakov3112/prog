#include <iostream>


struct Node {
    int key;
    Node* next = nullptr;
};

struct Fraction {
    int numerator;
    int denominator;
};

Fraction* minus(Fraction* f1, Fraction* f2) {
    Fraction* f = new Fraction;
    f->numerator = f1->numerator * f2->denominator - f2->numerator * f1->denominator;
    f->denominator = f1->denominator * f2->denominator;
    if (f->denominator >= 2) {
        for (int i = 2; i <= f->denominator; i++) {
            if (f->numerator % i == 0 && f->denominator % i == 0) {
                f->numerator /= i;
                f->denominator /= i;
            }
        }
    }
    return f;
}

bool isGreater(Fraction* f1, Fraction* f2) {
    return ((f1->numerator * f2->denominator) >= (f1->denominator * f2->numerator));
}

bool isZero(Fraction* f) {
    return (f->numerator == 0);
}


void print_node(Node* head) {
    if (head == nullptr) return;
    Node* current = head;
    while (current->next != nullptr) {
        std::cout << current->key << ' ';
        current = current->next;
    }
    if (current->key != 0) std::cout << current->key;
}

Node* egypt(Fraction* f) {
    Node* head = new Node;
    Node* current = head;
    if (f->numerator == 1) {
        head->key = f->denominator;
        return head;
    }
    int i = 2;
    while (!isZero(f)) {
        Fraction* tmp = new Fraction{1, i};
        if (isGreater(f, tmp)) {
            current->key = i;
            current->next = new Node;
            current = current->next;
            f = minus(f, tmp);
            ++i;
        } else ++i;
    }
    return head;
}


int main() {
    int M, N;
    std::cin >> M;
    std::cin >> N;
    Fraction* f = new Fraction{M, N};
    print_node(egypt(f));
    return 0;
}