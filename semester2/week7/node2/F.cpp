#include <iostream>

struct Node
{
    int key    = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct List
{
    Node *HEAD  = nullptr;
    Node *TAIL  = nullptr;
    Node *NIL   = nullptr;
    size_t size = 0;
};

List *create_empty_list() {
    List *list = new List;
    Node *NIL  = new Node;
    list->NIL  = NIL;
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    return list;
}

List* push_back(List* list_ptr, int new_key){
    if (list_ptr == nullptr){
        create_empty_list();
    }
    Node *NEW = new Node;
    NEW->key  = new_key;
    if (list_ptr->HEAD == list_ptr->NIL && list_ptr->TAIL == list_ptr->NIL){
        NEW->next = list_ptr->NIL;
        NEW->prev = list_ptr->NIL;
        list_ptr->HEAD = NEW;
        list_ptr->TAIL = NEW;
    } else {
        NEW->prev = list_ptr->TAIL;
        NEW->next = list_ptr->NIL;
        list_ptr->TAIL->next = NEW;
        list_ptr->TAIL = NEW;
    }
    list_ptr->size++;
    return list_ptr;
}

void print_list(const List* list_ptr){
    if (list_ptr == nullptr){
        return;
    }
    if (list_ptr->HEAD == list_ptr->TAIL){
        std::cout << list_ptr->HEAD->key << std::endl;
        return;
    }
    Node* current = list_ptr->HEAD;
    while(current->next != list_ptr->NIL){
        std::cout<< current->key << ' ';
        current = current->next;
    }
    std::cout << current->key << std::endl;
}

using std::cout;
using std::endl;


int main() {
  List* list = create_empty_list();
  list = push_back(list, 0);
  print_list(list);
  delete list->HEAD;
  delete list->NIL;
  delete list;
  return 0;
}