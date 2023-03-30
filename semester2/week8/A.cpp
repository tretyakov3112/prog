#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node {
  int key;
  Node* next;
};

Node* read_list(Node*& head) {
    int value;
    cin >> value;
    if (value == 0) {
        head = nullptr;
        return head;
    }
    head = new Node{value, nullptr};
    Node* curr = head;
    while (true) {
        cin >> value;
        if (value == 0) {
            curr->next = nullptr;
            break;
        }
        curr->next = new Node{value, nullptr};
        curr = curr->next;
    }
    return head;
}

void print_list(Node* head_ref) {
    if (head_ref == nullptr) {
        std::cout << std::endl; 
        return;
    }
    Node* current = head_ref; 
    while (current != nullptr) { 
        std::cout << current->key; 
        if (current->next != nullptr) {
            std::cout << " "; 
        } else {
            std::cout << std::endl;
        }
        current = current->next; 
    }
}

void destroy_list(Node*& head_ptr) {
    while (head_ptr != nullptr) { 
        Node* tmp = head_ptr; 
        head_ptr = head_ptr->next; 
        delete tmp; 
    } 
}


Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    auto new_head = new Node {0, prev};
    prev = new_head;
    return prev;
}

int main() {
  Node* head = nullptr;
  head = read_list(head);
  head = reverse(head);
  print_list(head);
  destroy_list(head);
  return 0;
}
