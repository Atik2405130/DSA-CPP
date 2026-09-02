#include <bits/stdc++.h>
using namespace std;
#define tata "\n"

// Definition of a node in the binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Global pointer to the root of the tree
struct Node *root = nullptr;

// Function to create a new node with a given value
Node *createNode(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// 1. Preorder Traversal: Root -> Left -> Right
void preorder(struct Node *rt)
{
    if (rt == nullptr)
        return;
    cout << rt->data << " "; // Visit root
    preorder(rt->left);      // Traverse left subtree
    preorder(rt->right);     // Traverse right subtree
}

// 2. Inorder Traversal: Left -> Root -> Right
void inorder(struct Node *rt)
{
    if (rt == nullptr)
        return;
    inorder(rt->left);       // Traverse left subtree
    cout << rt->data << " "; // Visit root
    inorder(rt->right);      // Traverse right subtree
}

// 3. Postorder Traversal: Left -> Right -> Root
void postorder(struct Node *rt)
{
    if (rt == nullptr)
        return;
    postorder(rt->left);     // Traverse left subtree
    postorder(rt->right);    // Traverse right subtree
    cout << rt->data << " "; // Visit root
}

// 4. Level Order Traversal: Visit nodes level by level from left to right
void levelOrder(struct Node *rt)
{
    if (rt == nullptr)
        return;
    queue<Node *> q; // Queue to hold nodes at each level
    q.push(rt);      // Start with the root node

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " "; // Visit current node

        // Enqueue left child first to maintain left-to-right order
        if (current->left != nullptr)
            q.push(current->left);
        // Enqueue right child
        if (current->right != nullptr)
            q.push(current->right);
    }
}
// --- Array-based Logic for Complete Binary Tree ---
int getParent(int i)
{
    return floor(i / 2.0);
}
int getLeftChild(int i)
{
    return 2 * i;
}
int getRightChild(int i)
{
    return 2 * i + 1;
}

int main()
{
    // Build the following sample tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Demonstrate all traversals
    cout << "Preorder   : ";
    preorder(root);
    cout << tata;
    cout << "Inorder    : ";
    inorder(root);
    cout << tata;
    cout << "Postorder  : ";
    postorder(root);
    cout << tata;
    cout << "Level Order: ";
    levelOrder(root);
    cout << tata;

    return 0;
}