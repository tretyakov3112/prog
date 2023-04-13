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
    if (head == nullptr){
        head = new Node;
        head->key = std::getchar();
        if (head->key == ')'){
            std::cout << "NO" << std::endl;
            return;
        }else if (head->key == '\n'){
            std::cout << "YES" << std::endl;
            return;
        }

        head->next = nullptr;
    }

    Node* current = head;
    Node* Next = current->next;
    Node* Prev = nullptr;
    while(current->key != '\n'){
        Next = new Node;
        Next->key = std::getchar();
        if (current->key == Next->key){
            std::cout << "NO" << std::endl;
            return;
        }
        Next->next = nullptr;
        Prev = current;
        current = Next;
        Next = Next->next;
    }

    if (Prev->key == '('){
        std::cout << "NO" << std::endl;
        return;
    } 

    std::cout << "YES" << std::endl;
    return;
}

int main() {
    Node *head  = nullptr;
    checker(head);
    destroy_list(head);
    return 0;
}