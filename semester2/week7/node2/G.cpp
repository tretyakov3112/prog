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

void clear_list(List* list_ptr){
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
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
}

using std::cout;
using std::endl;


int main() {
    List* list = create_empty_list();
    list = push_back(list, 0);
    list = push_back(list, 1);
    list = push_back(list, 2);
    list = push_back(list, 3);
    clear_list(list);
    if ((list->HEAD == list->TAIL) and (list->NIL != nullptr)) {
        cout << "OK" << endl;
    }
    delete list->NIL;
    delete list;
    return 0;
}