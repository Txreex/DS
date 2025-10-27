#include <iostream>
#define SIZE 5
using namespace std;

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }

    bool isFull() { return rear == SIZE - 1; }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
        cout << val << " inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << arr[front] << " removed\n";
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty!\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;

    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: q.peek(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}
