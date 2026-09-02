#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Create a stack of integers
    stack<int> st;

    // Push elements onto the stack
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;
    cout << "Stack size: " << st.size() << endl;

    // Pop elements from the stack
    cout << "\nRemoving elements:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
