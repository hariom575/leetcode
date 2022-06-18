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
    int minCameraCover(TreeNode* root) {
        int cam=0;
        int mincam=min(cam,cover(root,cam));
        if(mincam==0) cam++;
        return cam;
    }
    int cover(TreeNode * root,int &cam){
        if(!root) return 1;
        int left=cover(root->left,cam);
        int right=cover(root->right,cam);
        if(left==0 || right==0 ){
            cam++;
            return 2;
        }
        if(left==2 || right==2){
            return 1;
        }
        return 0;
    }
};