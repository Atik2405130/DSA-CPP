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
    void inOrder(TreeNode* root, int& k, int& ans) {
        if (root == NULL) return;

        // Right first (largest side)
        inOrder(root->right, k, ans);

        if (k == 0) return;   // early stop

        // Visit root
        if (--k == 0) {
            ans = root->val;
            return;
        }

        // Left
        inOrder(root->left, k, ans);
    }

    int kthLargest(TreeNode* root, int k) {
        int ans = -1;
        inOrder(root, k, ans);
        return ans;
    }
};
