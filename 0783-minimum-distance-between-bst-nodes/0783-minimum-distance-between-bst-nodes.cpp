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
    int ans = 111111;
    int cmp = -111111;
    int max(int a, int b){
      if (a > b) return a;
      return b;
    }
    int min(int a, int b){
      if (a > b) return b;
      return a;
    }
    int minDiffInBST(TreeNode* root) {
        
        if (root->left) {
          minDiffInBST(root->left);
        }
        ans = min(ans, root->val - cmp);
        cmp = root->val;
        if (root->right){
          minDiffInBST(root->right);
        }
        return ans;
    }
};