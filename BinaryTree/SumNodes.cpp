#include<iostream>
using namespace std;

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  int sumNodes(TreeNode *root){
    if(root==NULL)return 0;
    int leftsum=sumNodes(root->left);
    int rightsum=sumNodes(root->right);
    return leftsum+rightsum+root->val;
  }
