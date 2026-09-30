#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to implement Josephus problem
int josephus(int n, int k) {
    // Circular linked list create
    Node* head = new Node{1, nullptr};
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node{i, nullptr};
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head; // circular banado

    Node* temp = head;
    while (temp->next != temp) { // jab tak ek node bachi hai
        for (int i = 1; i < k; i++) {
            temp = temp->next; // k-1 steps
        }
        // delete kth node
        cout << "Deleting: " << temp->next->data << endl;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        temp = temp->next;
    }
    return temp->data; // last survivor
}

int main() {
    int n = 7, k = 3;
    cout << "Josephus Problem (n=7, k=3)" << endl;
    int survivor = josephus(n, k);
    cout << "Survivor: " << survivor << endl;
    return 0;
}

