#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 5   // Maximum size of stack

class Stack {
private:
    int arr[MAX];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Push operation
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack" << endl;
        }
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop" << endl;
        } else {
            cout << arr[top--] << " popped from stack" << endl;
        }
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element" << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

// Menu-driven program
int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 4:
                if (s.isFull())
                    cout << "Stack is full.\n";
                else
                    cout << "Stack is not full.\n";
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
