#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to delete nodes with even values
Node* deleteEven(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data % 2 == 0) { // agar even hai
            if (prev == nullptr) { // head delete karna hai
                head = temp->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
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
    // List create: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    cout << "Original List: ";
    printList(head);

    head = deleteEven(head);

    cout << "After Deleting Even Nodes: ";
    printList(head);

    return 0;
}

