#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    char key;
    Node *next;
};

void destroy_list(Node *&head_ptr) {
    Node *following = new Node;
    if (head_ptr != nullptr) {
        following = head_ptr->next;
    }

    while (head_ptr != nullptr) {
        delete head_ptr;
        head_ptr = following;
        if (following != nullptr) {
            following = following->next;
        }
    }
}


void checker(Node* head){
    char c = std::getchar();
    if (c == ')'){
        std::cout << "NO" << std::endl;
        return;
    } else if (c == '\n' || c == '\0'){
        std::cout << "YES" << std::endl;
        return;
    }

    head = new Node;
    head->key = c;
    head->next = nullptr;

    Node* current = head;
    while((c = std::getchar()) != '\n' && c != '\0'){
        Node* Next = new Node;
        Next->key = c;
        Next->next = nullptr;
        if (current->key == '(' && Next->key == ')') {
            current = current->next;
            delete Next;
        } else {
            current->next = Next;
            current = Next;
        }
    }

    if (current->key == '('){
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    destroy_list(head);
}

int main() {
    Node *head  = nullptr;
    checker(head);
    destroy_list(head);
    return 0;
}