#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to delete even positioned nodes
Node* deleteEvenPos(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    Node* prev = nullptr;
    int pos = 1; // position counter

    while (temp != nullptr) {
        if (pos % 2 == 0) { // agar position even hai
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
        pos++;
    }
    return head;
}

// Helper function to print list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // List create: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};
    head->next->next->next->next = new Node{50, nullptr};

    cout << "Original List: ";
    printList(head);

    head = deleteEvenPos(head);

    cout << "After Deleting Even Positioned Nodes: ";
    printList(head);

    return 0;
}

