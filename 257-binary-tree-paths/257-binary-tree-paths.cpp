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
    vector<string>ans;
    void btp(TreeNode* &root,string m){
     if (root && !root->left&&!root->right) {ans.push_back(m+to_string(root->val));}
     if (!root) return;
        string n=to_string(root->val)+'-'+'>'; 
        btp(root->left,m+n);
        btp(root->right,m+n);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string m="";
        btp(root,m);
        return ans;
    }
};