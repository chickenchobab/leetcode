/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int l, h;
    int dfs(TreeNode* cur){
      int s = 0;
      if (cur->val <= h && cur->val >= l){
        s += cur->val;
      }
      if (cur->left) s += dfs(cur->left);
      if (cur->right) s += dfs(cur->right);
      return s;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->l = low;
        this->h = high;
        return dfs(root);
    }
};