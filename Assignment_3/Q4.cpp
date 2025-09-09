#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

char match(char c){
    if(c == ')'){
        return '(';
    }else if(c == ']'){
        return '[';
    }else if(c == '}'){
        return '{';
    }
    return '\0';
}

bool balancedParentheses(std::string expr){
    stack<char> s;
    for(char val : expr){
        if (val == '(' || val == '[' || val == '{') {
            s.push(val);
        }else if(val == ')' || val == ']' || val == '}'){
            if(s.empty()||s.top() != match(val)){
                return false;
            }else{
                s.pop();
            }
        }
    }

    if(s.empty()){
        return true;
    }
    return false;
}

string infixToPostfix(string infix) {
    if(!balancedParentheses(infix)) return "\0";
    stack<char> s;
    string postfix = "";

    for (char val : infix) {
        if (val == '(') {
            s.push(val);
        }
        else if (val == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // remove '('
        }
        else if (isOperator(val)) {
            while (!s.empty() && precedence(s.top()) >= precedence(val)) {
                postfix += s.top();
                s.pop();
            }
            s.push(val);
        }else{
            postfix += val;
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}


int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
