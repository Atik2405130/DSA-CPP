#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string postfixToPrefix(string postfix) {
    stack<string> s;
    
    for (char ch : postfix) {
        if (isalnum(ch)) {
            s.push(string(1, ch));
        }
        else if (isOperator(ch)) {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string expr = ch + op1 + op2;
            s.push(expr);
        }
    }
    return s.top();
}

int main() {
    string expr = "AB+C*";
    cout << "Postfix: " << expr << endl;
    cout << "Prefix: " << postfixToPrefix(expr) << endl;
    return 0;
}