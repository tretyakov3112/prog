// Реализуйте функцию добавление нового узла в список List* push_front(List* list_ptr, int new_key)

//     List* list_ptr -- указатель на список, может быть nullptr
//     int new_key -- значение ключа для нового узла

// Функция создает новый узел и добавляет его в начало списка. Если list_ptr == nullptr, то нужно создать пустой список и добавить элемент в него

// Учтите все возможные крайние случаи!!!

// Для проверки кода можно воспользоваться следующим шаблоном:

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

List* push_front(List* list_ptr, int new_key) {
    Node* new_node = new Node;
    new_node->key = new_key;
    
    if (list_ptr == nullptr) list_ptr = create_empty_list();
  
    
    new_node->prev = list_ptr->NIL;
    new_node->next = list_ptr->HEAD;
    list_ptr->HEAD->prev = new_node;
    list_ptr->HEAD = new_node;
    
    if (list_ptr->size == 0) list_ptr->TAIL = new_node;
    
    list_ptr->size++;
    
    return list_ptr;
}

using std::cout;
using std::endl;


int main() {
  List* list = create_empty_list();
  list = push_front(list, 0);
  if ((list->HEAD->key == 0) and (list->TAIL->key == 0)) {
    cout << "OK" << endl;
  }
  delete list->HEAD;
  delete list->NIL;
  delete list;
  return 0;
}