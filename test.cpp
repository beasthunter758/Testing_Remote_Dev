#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(Node* head) {
    Node* curr = head;

    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }

    std::cout << std::endl;
}

int main() {
    // create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, nullptr}}}}};

    std::cout << "Original list: ";
    printList(head);

    // reverse the list
    Node* newHead = reverseList(head);

    std::cout << "Reversed list: ";
    printList(newHead);

    return 0;
}
