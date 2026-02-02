#include"PreInPostTraversal.hpp"
using namespace std;

void KthLevel(Node *root,int K){
    if(root==NULL)return;
    if(K==1){
        cout<<root->data;
        return;
    }
    KthLevel(root->left,K-1);
    KthLevel(root->right,K-1);
}