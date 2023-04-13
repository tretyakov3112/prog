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

void destroy_list(List* list_ptr){
    if (list_ptr == nullptr){
        return;
    }
    
    Node* current = list_ptr->HEAD;

    while (current != list_ptr->TAIL){
        Node* Next = current->next;
        delete current;
        list_ptr->size--;
        current = Next;
    }

    delete current;
    list_ptr->size--;
    delete list_ptr->NIL;
    delete list_ptr;
}

Node* find_key(List* list_ptr, int key){
    Node* current = list_ptr->HEAD;

    while(current != list_ptr->NIL){
        if(current->key == key){
            return current;
        }
        current=current->next;
    }
    return current;
}

using std::cout;
using std::endl;

int main() {
  List* list = create_empty_list();
  Node* ptr = nullptr;
  push_back(list, 0);
  push_back(list, 1);
  push_back(list, 2);
  ptr = find_key(list, 2);
  if (ptr == list->TAIL) {
    cout << "OK" << endl;
  }
  destroy_list(list);
  return 0;
}