#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* mergeTwoLists(Node* head1, Node* head2) {
  if (head1 == nullptr) return head2;
  if (head2 == nullptr) return head1;
  Node* current = head1;
  while (current->next != nullptr) current = current->next;
  current->next = head2;
  return head1;
}

using std::cout;
using std::cin;
using std::endl;

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
        std::cout << current->data; 
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

int main() {
  Node* head1 = nullptr;
  head1 = read_list(head1);
  Node* head2 = nullptr;
  head2 = read_list(head2);
  Node* new_list = mergeTwoLists(head1, head2);
  print_list(new_list);
  destroy_list(new_list);
  return 0;
}

