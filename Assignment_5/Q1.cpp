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

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
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

    void insertRelative(int value, int target, bool after) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;

        if (!after) {
            if (head->data == target) {
                insertAtBeginning(value);
                return;
            }
            while (temp->next && temp->next->data != target)
                temp = temp->next;

            if (temp->next == nullptr) {
                cout << "Target node not found.\n";
                return;
            }

            Node* newNode = new Node{value, temp->next};
            temp->next = newNode;
        }
        else {
            while (temp && temp->data != target)
                temp = temp->next;

            if (temp == nullptr) {
                cout << "Target node not found.\n";
                return;
            }

            Node* newNode = new Node{value, temp->next};
            temp->next = newNode;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Deletion of a specific node
    void deleteSpecific(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Node not found.\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // (g) Search for a node
    void search(int value) {
        Node* temp = head;
        int position = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << position << ".\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Node not found.\n";
    }

    // (h) Display all node values
    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// Main menu-driven interface
int main() {
    LinkedList list;
    int choice, value, target;
    bool after;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search for a Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Insert after target? (1 for Yes, 0 for No): ";
                cin >> after;
                list.insertRelative(value, target, after);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter node value to delete: ";
                cin >> value;
                list.deleteSpecific(value);
                break;
            case 7:
                cout << "Enter node value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
