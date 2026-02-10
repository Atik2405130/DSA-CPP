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
    void elementSorted(TreeNode *root,vector<int>&vec){
        if(root==nullptr)return;
        elementSorted(root->left,vec);
        vec.push_back(root->val);
        elementSorted(root->right,vec);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>vec;
        elementSorted(root,vec);
        int m=vec[1]-vec[0];
        for(int i=1;i<vec.size()-1;i++){
            m=min(m,(vec[i+1]-vec[i]));
        }
        return m;
    }
};