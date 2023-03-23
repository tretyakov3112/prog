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

using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  Node* ptr = HEAD;
  while (ptr->next != nullptr) {
    cout << ptr->key << ' ';
    ptr = ptr->next;
  }
  cout << ptr->key << endl;
  ptr = HEAD;
  while (ptr->next != nullptr) {
    ptr = HEAD->next;
    delete HEAD;
    HEAD = ptr;
  }
  delete HEAD;
  return 0;
}

