#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void findMiddle() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* slow = head;  
        Node* fast = head;  

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle element: " << slow->data << "\n";
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "Linked List: ";
    list.display();

    list.findMiddle();

    return 0;
}
