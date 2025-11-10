#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() : head(NULL) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    int size() {
        if (!head) return 0;
        int count = 0;

        Node* temp = head;

        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }


    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        cll.insert(val);
    }

    cll.display();
    cout << "Size of Circular Linked List: " << cll.size() << endl;

    return 0;
}
