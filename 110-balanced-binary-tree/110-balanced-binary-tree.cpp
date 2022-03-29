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
    int height(TreeNode *root,bool &h){
        if(root==NULL) return 0;
        int l=height(root->left,h);
        int r=height(root->right,h);
        if(abs(r-l)>1) h=false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool h=true;
        int x=height(root,h);
        cout<<x<<" ";
        return h;
    }
};