#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data=val;
        left=right=nullptr;
    }
};
static int idx=-1;
Node *buildTree(vector<int>&preorder){
    idx++;
    if(preorder[idx]==-1)return NULL;
    Node *root=new Node(preorder[idx]);
    root->left=buildTree(preorder); //left subtree
    root->right=buildTree(preorder); //right subtree
    return root;
}
void preOrder(Node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root){
    if(root==nullptr)return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node *root){
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
}
void levelOrder(Node *root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node *curr=q.front();
        q.pop();
        if(curr==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else break;
        }
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node *root=buildTree(preorder);
    cout<<root->data<<endl;
    cout<<"PreOrder: ";
    preOrder(root);
    cout<<endl;
    cout<<"InOrder: ";
    inOrder(root);
    cout<<"PostOrder: ";
    postOrder(root);
    cout<<endl;
    cout<<"LevelOrder: ";
    levelOrder(root);
    return 0;
}

