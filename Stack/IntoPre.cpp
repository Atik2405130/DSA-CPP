#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string infixToPrefix(string infix) {
    // Step 1: Reverse infix
    reverse(infix.begin(), infix.end());
    
    // Step 2: Swap '(' and ')'
    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    
    // Step 3: Convert to postfix
    stack<char> s;
    string result = "";
    
    for (char ch : infix) {
        if (isspace(ch)) continue;
        
        if (isalnum(ch)) {
            result += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop(); // remove '('
        }
        else if (isOperator(ch)) {
            while (!s.empty() && s.top() != '(' && 
                   precedence(s.top()) > precedence(ch)) {
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    
    // Step 4: Reverse result
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string expr = "(A+B)*C";
    cout << "Infix: " << expr << endl;
    cout << "Prefix: " << infixToPrefix(expr) << endl;
    return 0;
}