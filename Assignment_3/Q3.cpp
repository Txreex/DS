#include<iostream>
#include<stack>
using namespace std;

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

int main(){
    cout<<balancedParentheses("((a+b) * (c-d)")<<endl;  //false
}