

// Реализуйте функцию Node* find(Node* head_ref, int key)

//     Node* head_ref -- указатель на первый узел односвязного списка
//     int key -- значение ключа для поиска

// Функция находит указатель на узел, который содержит key. Если такого узла нет, то возвращает nullptr

// Для проверки кода можно воспользоваться следующим шаблоном

#include <iostream>

struct Node {
    int key = 0;
    Node* next = nullptr;
};

void push_back(Node*& head_ref, int new_data) {
    auto new_tail = new Node {new_data, nullptr};
    if (head_ref == nullptr) head_ref = new_tail;
    else {
        Node* ref = head_ref;
        while (ref->next != nullptr) ref = ref->next;
        ref->next = new_tail;
    }
}

void destroy_list(Node*& head_ptr) {
    while (head_ptr != nullptr) { 
        Node* tmp = head_ptr; 
        head_ptr = head_ptr->next; 
        delete tmp; 
    } 
}

Node* find(Node* head_ref, int key) {
    if (head_ref == nullptr) return nullptr;
    Node* current = head_ref;
    while (current != nullptr) {
        if (current->key == key) return current;
        current = current->next;
    }
    return nullptr;
}

using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr, *current = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  current = find(HEAD, 2);
  if (current->key == 2) {
    cout << "OK" << endl;
  }
  return 0;
}

