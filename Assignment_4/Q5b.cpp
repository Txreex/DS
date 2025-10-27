#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size-- > 1) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << q.front() << " popped\n";
        q.pop();
    }

    void top() {
        if (q.empty()) cout << "Stack is Empty!\n";
        else cout << "Top: " << q.front() << endl;
    }

    bool empty() { return q.empty(); }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.top();
    s.pop();
    s.top();
}
