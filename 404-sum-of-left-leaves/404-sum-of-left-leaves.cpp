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
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (not root->left and not root->right)
            return 0;
        
        helper(root);
        return sum;
    }
    
    void helper(TreeNode* root, bool isleft = false) {
        if (not root) return;
        if (isleft and (not root->left and not root->right))
            sum += root->val;
        helper(root->left, true);
        helper(root->right);
    }
};
