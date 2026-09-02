#include <bits/stdc++.h>
using namespace std;
#define tata "\n"

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;

    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node *treeMinimum(Node *x)
{
    while (x->left != nullptr)
        x = x->left;
    return x;
}

Node *treeSearch(Node *x, int k)
{
    if (x == nullptr || k == x->data)
        return x;
    if (k < x->data)
        return treeSearch(x->left, k);
    else
        return treeSearch(x->right, k);
}

void treeInsert(Node *&root, int k)
{
    Node *z = new Node(k);
    Node *y = nullptr;
    Node *x = root;

    while (x != nullptr)
    {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == nullptr)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// The TRANSPLANT function replaces the subtree rooted at node u
// with the subtree rooted at node v.
void transplant(Node *&root, Node *u, Node *v)
{
    if (u->parent == nullptr)
    {
        root = v; // u was the root
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v; // u was a left child
    }
    else
    {
        u->parent->right = v; // u was a right child
    }

    if (v != nullptr)
    {
        v->parent = u->parent; // Update v's parent
    }
}

void treeDelete(Node *&root, Node *z)
{
    if (z == nullptr)
        return;

    // Case 1: z has no left child (Replace z with right child)
    if (z->left == nullptr)
    {
        transplant(root, z, z->right);
    }
    // Case 2: z has no right child (Replace z with left child)
    else if (z->right == nullptr)
    {
        transplant(root, z, z->left);
    }
    // Case 3: z has two children
    else
    {
        // Find successor y (minimum in right subtree)
        Node *y = treeMinimum(z->right);

        // CASE B: Successor y is NOT the immediate right child of z
        // We must first replace y with its own right child,
        // and then turn y into z's right child.
        if (y->parent != z)
        {
            transplant(root, y, y->right); // Line 7 in slide
            y->right = z->right;           // Line 8
            y->right->parent = y;          // Line 9
        }

        // CASE A (and cleanup for Case B): Replace z with y
        transplant(root, z, y); // Line 10
        y->left = z->left;      // Line 11
        y->left->parent = y;    // Line 12
    }
    delete z; // Free memory
}

int main()
{
    Node *root = nullptr;
    // Tree Construction: 15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9
    int keys[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (int k : keys)
        treeInsert(root, k);

    cout << "Initial Tree: ";
    inorder(root);
    cout << tata;

    // Test 1: Delete Leaf (9) - Standard Transplant
    cout << "Deleting 9 (Leaf)..." << tata;
    treeDelete(root, treeSearch(root, 9));
    inorder(root);
    cout << tata;

    // Test 2: Delete Node with One Child (7) - Standard Transplant
    cout << "Deleting 7 (One Child)..." << tata;
    treeDelete(root, treeSearch(root, 7));
    inorder(root);
    cout << tata;

    // Test 3: Delete Node with Two Children (6)
    // In this specific tree state, 6 has children 3 and 13.
    // The successor of 6 is 13.
    // Since 13 IS the immediate right child of 6, this triggers CASE A.
    cout << "Deleting 6 (Two Children, Case A logic)..." << tata;
    treeDelete(root, treeSearch(root, 6));
    inorder(root);
    cout << tata;
    return 0;
}