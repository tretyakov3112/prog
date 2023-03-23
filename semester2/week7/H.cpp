

// Реализуйте функцию void remove_key(Node*& head_ref, int key)

//     Node*& head_ref -- ссылка на указатель на первый узел односвязного списка
//     int key -- значение, по которому требуется удалить узел

// Функция удаляет первый узел с указанным значением key и освобождает выделенную память

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

void remove_key(Node*& head_ptr, int key) {
    if (head_ptr != nullptr) {
        if (head_ptr->key == key) { 
            Node* temp = head_ptr;
            head_ptr = head_ptr->next;
            delete temp;
            return;
        }
        Node* prev = head_ptr;
        Node* current = head_ptr->next;
        while (current != nullptr) {
            if (current->key == key) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
}


using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  remove_key(HEAD, 0);
  remove_key(HEAD, 1);
  remove_key(HEAD, 2);
  remove_key(HEAD, 3);
  if (HEAD == nullptr) {
    cout << "OK" << endl;
  }
  return 0;
}

