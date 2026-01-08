#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string prefixToInfix(string prefix) {
    stack<string> s;
    
    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isalnum(ch)) {
            s.push(string(1, ch));
        }
        else if (isOperator(ch)) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string expr = "(" + op1 + ch + op2 + ")";
            s.push(expr);
        }
    }
    return s.top();
}

int main() {
    string expr = "*+ABC";
    cout << "Prefix: " << expr << endl;
    cout << "Infix: " << prefixToInfix(expr) << endl;
    return 0;
}