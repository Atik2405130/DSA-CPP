#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Node {
public:
    int key;
    int height;

    Node *left;
    Node *right;

    Node(int value) {
        key = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};
class AVLTree {
private:
    Node *root;
    int get_height(Node *node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }
    void update_height(Node *node) {
        if (node == nullptr)
            return;
        node->height =1+max(get_height(node->left),get_height(node->right));
    }
    int get_balance(Node *node) {
        if (node == nullptr)
            return 0;

        return get_height(node->left)-get_height(node->right); //positive-->left heavy
    }
    Node *right_rotate(Node *y) {

        Node *x = y->left;
        Node *temp = x->right;

        x->right = y;
        y->left = temp;

        update_height(y);
        update_height(x);
        return x;
    }
    Node *left_rotate(Node *x) {

        Node *y = x->right;
        Node *temp = y->left;

        y->left = x;
        x->right = temp;

        update_height(x);
        update_height(y);

        return y;
    }
    Node *rebalance(Node *node) { //Rebalance
        if (node == nullptr)
            return nullptr;
        update_height(node);

        int balance=get_balance(node);
        if (balance > 1) { //--> left heavy
            //LR
            if (get_balance(node->left) < 0) {
                node->left =
                    left_rotate(node->left);
            }

            //LL
            return right_rotate(node);
        }
        if (balance < -1) { //-->right heavy
            //RL
            if (get_balance(node->right) > 0) {
                node->right =
                    right_rotate(node->right);
            }
            //RR
            return left_rotate(node);
        }
        return node;
    }
    Node *insertNode(Node *node,int key,bool &inserted) {
        if (node==nullptr) {
            inserted=true;
            return new Node(key);
        }
        if (key < node->key) {
            node->left =insertNode(node->left,key,inserted);
        }
        else if (key > node->key) {
            node->right =insertNode(node->right,key,inserted);
        }
        else {
            inserted = false;
            return node;
        }
        return rebalance(node);
    }
    Node *findMinimum(Node *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    Node *delete_node(Node *node,int key,bool &deleted) {
        if (node == nullptr) {
            deleted = false;
            return nullptr;
        }
        if (key < node->key) {
            node->left =delete_node(node->left,key,deleted);
        }
        else if (key > node->key) {
            node->right =delete_node(node->right,key,deleted);
        }
        else {
            // Key found
            deleted = true;
            if (node->left == nullptr) { // left child not exist
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) { //right child not exist
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node *temp = findMinimum(node->right);
                node->key = temp->key;
                bool dummy;
                node->right = delete_node(node->right,temp->key,dummy);
            }
        }
        return rebalance(node); //rebalance the tree
    }
    void inorder(Node *node,vector<int> &result) {
        if (node == nullptr)
            return;
        inorder(node->left, result);
        result.push_back(node->key);
        inorder(node->right, result);
    }
    string make_string(Node *node) {
        if (node == nullptr)
            return "";
        if (node->left == nullptr && node->right == nullptr) {
            return to_string(node->key);
        }
        string left = make_string(node->left);
        string right = make_string(node->right);
        return to_string(node->key)+ "(" + left + "," + right + ")";
    }
    void clear(Node *node) {
        if (node == nullptr)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
public:
    AVLTree() {
        root = nullptr;
    }
    ~AVLTree() {
        clear(root);
    }
    bool insert(int key) {
        bool inserted = false;
        root =insertNode(root,key,inserted);
        return inserted;
    }
    bool erase(int key) {
        bool deleted = false;
        root = delete_node(root,key,deleted);
        return deleted;
    }
    bool find(int key) {

        Node *current = root;

        while (current != nullptr) {

            if (key == current->key) {
                return true;
            }
            if (key < current->key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }

    vector<int> traverse() {

        vector<int>res;

        inorder(root,res);

        return res;
    }
    string treeString() {
        return make_string(root);
    }
};


int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout<<"Usage: "<<argv[0]<<" <input-file> <output-file>\n";
        return 1;
    }

    ifstream input(argv[1]);
    ofstream output(argv[2]);

    if (!input.is_open() || !output.is_open()) {
        cout << "Could not open file.\n";
        return 1;
    }
    AVLTree tree;
    string command;
    while (input>>command) {

        if (command == "I") { //Insert
            int x;
            input >> x;
            bool success = tree.insert(x);
            if (success) {
                output << tree.treeString()<<'\n';
            }
            else {
                output << "duplicate\n";
            }
        }
        else if (command == "D") { //Delete
            int x;
            input >> x;
            bool success = tree.erase(x);
            if (success) {
                output << tree.treeString() << '\n';
            }
            else {
                output << "not found\n";
            }
        }
        else if (command == "F") { //Find 
            int x;
            input >> x;
            bool found = tree.find(x);
            if (found){
                output<<"found\n";
            }
            else {
                output<<"not found\n";
            }
        }
        else if (command == "T") {
            vector<int> values = tree.traverse();
            for (int i = 0;i<(int)values.size();i++) {
                if (i != 0)
                    output << " ";
                output << values[i];
            }
            output << '\n';
        }
    }
    input.close();
    output.close();
    return 0;
}