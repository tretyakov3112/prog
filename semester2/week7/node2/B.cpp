#include <iostream>

struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    int key = 0;
};

struct List {
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size;
};

List* create_empty_list() {
    List* list = new List;
    list->NIL = new Node;
    list->NIL->prev = list->NIL;
    list->NIL->next = list->NIL;
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    list->size = 0;
    return list;
}

using std::cout;
using std::endl;


int main() {
  List* list = create_empty_list();
  if ((list->HEAD != nullptr) and (list->TAIL != nullptr) and (list->NIL != nullptr)) {
    cout << "OK" << endl;
  }
  delete list->NIL;
  delete list;
  return 0;
}
