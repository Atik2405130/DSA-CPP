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
 
class Solution {
public:
    bool isSame(TreeNode *root,TreeNode *root2){
        if(root==NULL || root2==NULL){
            return root==root2;
        }
        bool isleft,isright;
        isleft=isSame(root->left,root2->left);
        isright=isSame(root->right,root2->right);
        return isleft && isright && root->val==root2->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot==NULL){
            return root==subRoot;
        }
        if(root->val==subRoot->val && isSame(root,subRoot)){
            return true;
        }
        else return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot); //val comparison and left-right checking
    }
};