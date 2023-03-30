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


int find_middle(const Node* head) {
    const Node* slow = head;
    const Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    int slow_key;
    if (fast != nullptr && fast->next == nullptr) {
      slow_key = slow->next->key;
    } else {
      slow_key = slow->key;
    }
    while (head != nullptr) { 
        const Node* tmp = head; 
        head = head->next; 
        delete tmp; 
    } 
    return slow_key;
}

int main() {
  Node* head = nullptr;
  head = read_list(head);
  cout << find_middle(head);
  return 0;
}
