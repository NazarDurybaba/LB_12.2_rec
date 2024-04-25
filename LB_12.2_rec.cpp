#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    if (head == nullptr) {
        head = createNode(data);
    }
    else {
        head->next = insertNode(head->next, data);
    }
    return head;
}

void printList(Node* head) {
    if (head != nullptr) {
        std::cout << head->data << " ";
        printList(head->next);
    }
}

int sumPositiveValues(Node* head) {
    if (head == nullptr) {
        return 0;
    }
    else if (head->data > 0) {
        return head->data + sumPositiveValues(head->next);
    }
    else {
        return sumPositiveValues(head->next);
    }
}

int main() {
    Node* head = nullptr;
    head = insertNode(head, 1);
    head = insertNode(head, -2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, -5);

    std::cout << "List: ";
    printList(head);
    std::cout << "\n";

    int sum = sumPositiveValues(head);
    std::cout << "Sum positive values: " << sum << "\n";

    return 0;
}
