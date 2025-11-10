#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char val) : data(val), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() : head(NULL) {}

    void insert(char val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    void display() {
        Node* temp = head;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    bool isPalindrome() {
        if (!head || !head->next) return true;

        Node* left = head;
        Node* right = head;

        while (right->next)
            right = right->next;

        while (left != right && right->next != left) {  // odd => left != right  even => right->next != left
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }

        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        dll.insert(ch);
    }

    dll.display();

    if (dll.isPalindrome())
        cout << "palindrome.\n";
    else
        cout << "NOT a palindrome.\n";

    return 0;
}

