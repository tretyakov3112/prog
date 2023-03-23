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

using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  destroy_list(HEAD);
  if (HEAD == nullptr) {
    cout << "OK" << endl;
  }

return 0;
}

