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

    void insert(int value) {
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

    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "\n";
    }

    int countAndDelete(int key) {
        int count = 0;

        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                count++;
            } else {
                current = current->next;
            }
        }

        return count;
    }
};

int main() {
    LinkedList list;
    int key;
    
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);

    cout << "Original Linked List: ";
    list.display();

    cout << "Enter key to delete: ";
    cin >> key;

    int count = list.countAndDelete(key);

    cout << "Count: " << count << "\n";
    cout << "Updated Linked List: ";
    list.display();

    return 0;
}

