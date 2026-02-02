#include<iostream>
using namespace std;
#include<vector>

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int sumTree(TreeNode *root){
        if(root==NULL)return 0;
        int left=sumTree(root->left);
        int right=sumTree(root->right);
        root->val+=left+right;
        return root->val;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)return NULL;
        sumTree(root);
        return root;
    }
};