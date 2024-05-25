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
    TreeNode *root;
    int ans = 0;
    int max(int a, int b){
        if (a > b) return a;
        return b;
    }
    int dfs(TreeNode* cur, int l){
        int a, b;
        if (cur->left == NULL && cur->right == NULL)
            return l;
        a = 0, b = 0;
        if (cur->left){
            a = dfs(cur->left, l + 1);
        }
        if (cur->right){
            b = dfs(cur->right, l + 1);
        }
        
        // cout << a << ' ' << b << '\n';
        ans = max(ans, a - l + b - l);
        return max(a, b);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        this->root = root;
        dfs(root, 0);
        return ans;
    }
};