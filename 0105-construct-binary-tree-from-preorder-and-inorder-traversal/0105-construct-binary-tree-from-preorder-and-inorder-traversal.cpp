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
     TreeNode* build(int s, int e, int p, vector<int>& preorder, vector<int>& inorder){
      
      if (s >= e) return nullptr;
      if (p >= preorder.size()) return nullptr;
       
      TreeNode *root = new TreeNode(preorder[p]);
      
      int i;
      for (i = s; i < e; ++ i){
        if (inorder[i] == preorder[p]) break;
      }
      root->left = build(s, i, p + 1, preorder, inorder);
      root->right = build(i + 1, e, p + (i - s + 1), preorder, inorder);
       
      return root;
    }
  
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return build(0, inorder.size(), 0, preorder, inorder);
    }
};