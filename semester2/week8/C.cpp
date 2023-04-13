#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int key;
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

void print_list(Node *head_ptr) {
    if (head_ptr == nullptr) {
        std::cout << std::endl;
        return;
    }
    Node *current = head_ptr;
    while (current->next != nullptr) {
        std::cout << current->key << ' ';
        current = current->next;
    }
    std::cout << current->key << std::endl;
}

void push_back(Node *&head, int new_key) {
    if (head == nullptr) {
        head = new Node;
        head->key  = new_key;
        head->next = nullptr;
        return;
    }
    Node *current = head;
    while (current->next != nullptr)
        current = current->next;
    current->next = new Node;
    current->next->key  = new_key;
    current->next->next = nullptr;
}

Node *read_list(Node *head) {
    int new_key = 0;

    cin >> new_key;

    while (new_key != 0) {
        push_back(head, new_key);
        cin >> new_key;
    }
    return head;
}

Node *reverse(Node *head) {
    if (head == nullptr) {
        return head;
    }

    Node *current = head;
    Node *Next = current->next;
    Node *Prev = nullptr;

    while (Next != nullptr) {
        current->next = Prev;
        Prev = current;
        current = Next;
        Next = Next->next;
    }
    current->next = Prev;
    head = current;
    return head;
}

Node *mergeTwoLists(Node *list1, Node *list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    Node *current1 = list1;
    Node *current2 = list2;
    while (current2 != nullptr) {
        while (current2->key > current1->next->key && current1->next != nullptr)
            current1 = current1->next;
        Node *Next = current1->next;
        Node *new_el = new Node;
        current1->next = new_el;
        new_el->key = current2->key;
        new_el->next = Next;
        current2 = current2->next;
    }
    return list1;
}

int main() {
    Node *list1 = nullptr;
    Node *list2 = nullptr;
    list1 = read_list(list1);
    list2 = read_list(list2);
    list1 = reverse(list1);
    list2 = reverse(list2);
    Node *merged = mergeTwoLists(list1, list2);
    print_list(list1);
    print_list(list2);
    print_list(merged);
    destroy_list(merged);
    return 0;
}