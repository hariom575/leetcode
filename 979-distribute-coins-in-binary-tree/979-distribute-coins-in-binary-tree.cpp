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
    
    int distributeCoinsHelper(TreeNode* root, int &ans) {
        if(!root) {
            return 0;
        }
        
        int l = distributeCoinsHelper(root->left, ans);
        int r = distributeCoinsHelper(root->right, ans);
        
		// one subtree would need coin and the other one could push coins up, 
		// so take a absolute
        ans += abs(l) + abs(r);
		
		// number if excahnges needed so that all node in the root subtree have 1 coin each
        return root->val + l + r - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int ans = 0;
        distributeCoinsHelper(root, ans);
        return ans;
    }
};