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
    int ans = 0;
    int dfs(TreeNode *cur, int l){
        int a, b;
        if (cur == NULL) return l;
        if (cur->left == NULL && cur->right == NULL) return l;

        a = 0, b = 0;

        if (cur->left){

        if (cur->left->val == cur->val) a = dfs(cur->left, l + 1);
        else dfs(cur->left, 0);
        }

        if (cur->right){

        if (cur->right->val == cur->val) b = dfs(cur->right, l + 1);
        else dfs(cur->right, 0);
        }
        
        if (a == 0 && b == 0) return l;
        ans = max(ans, a - l + b - l);
        return a > b ? a : b;
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};