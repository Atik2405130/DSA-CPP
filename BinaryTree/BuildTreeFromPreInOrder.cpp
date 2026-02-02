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
    int search(vector<int>&inorder,int value,int left,int right){
        for(int i=left;i<=right;i++){
            if(inorder[i]==value)return i;
        }
        return -1;
    }
    TreeNode *helper(vector<int>&preorder,vector<int>&inorder,int left,int right,int &preIdx){
        if(left>right)return NULL;
        TreeNode *root=new TreeNode(preorder[preIdx]);
        int Inidx=search(inorder,preorder[preIdx],left,right);
        preIdx++;
        root->left=helper(preorder,inorder,left,Inidx-1,preIdx);
        root->right=helper(preorder,inorder,Inidx+1,right,preIdx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx=0;
        int left=0;
        int right=preorder.size()-1;
        return helper(preorder,inorder,left,right,preIdx);
    }
};