#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> s;

    // Push all characters into stack
    for (char c : str) {
        s.push(c);
    }

    // Pop from stack and build reversed string
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string output = reverseString(input);
    cout << "Reversed string: " << output << endl;

    return 0;
}

