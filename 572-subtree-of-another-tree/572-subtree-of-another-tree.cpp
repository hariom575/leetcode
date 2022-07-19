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
    bool check(TreeNode *root1,TreeNode *root2){
        if(root1==NULL){
            if(root2==NULL) return true;
            return false;
        }
        if(root2==NULL){
            if(root1==NULL) return true;
            return false;
        }
        if(root1->val==root2->val){
            return check(root1->left,root2->left) && check(root1->right,root2->right);
        }
        return false;
    }
    bool helper(TreeNode *root1,TreeNode *root2){
        if(root1==NULL) return false;
        if(root1->val==root2->val){
            if(check(root1,root2)){
                return true;
            }
            return helper(root1->left,root2) || helper(root1->right,root2);
        }
        return helper(root1->left,root2) || helper(root1->right,root2);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root,subRoot);
    }
};