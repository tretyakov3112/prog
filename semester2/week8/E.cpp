#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    char type;
    int id;
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
        if (head->key == ')' || head->key == '>' || head->key == '}' || head->key == ']'){
            std::cout << "NO" << std::endl;
            return;
        }else if (head->key == '\n'){
            std::cout << "YES" << std::endl;
            return;
        }

        if (head->key == '(') head->type = 'c';
        if (head->key == '{') head->type = 'o';
        if (head->key == '[') head->type = 's';
        if (head->key == '<') head->type = 't';
        head->id = 1;
        head->next = nullptr;
    }

    Node* current = head;
    Node* Next = current->next;
    Node* Prev = nullptr;
    while(current->key != '\n'){
        Next = new Node;
        Next->key = std::getchar();

        if (Next->key == '}' || Next->key == '>' || Next->key == ']' || Next->key == ')') Next->id = 0;
        else Next->id = 1;

        if (Next->key == '(' || Next->key == ')') Next->type = 'c';
        if (Next->key == '{' || Next->key == '}') Next->type = 'o';
        if (Next->key == '[' || Next->key == ']') Next->type = 's';
        if (Next->key == '<' || Next->key == '>') Next->type = 't';

        if (current->id == Next->id || (current->id == 1 && current->type != Next->type)){
            std::cout << "NO" << std::endl;
            return;
        }

        Next->next = nullptr;
        Prev = current;
        current = Next;
        Next = Next->next;
    }

    if (Prev->id == 1){
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