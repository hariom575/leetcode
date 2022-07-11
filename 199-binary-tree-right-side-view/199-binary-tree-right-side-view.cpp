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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int sz=q.size();
            bool flag=true;
            while(sz--){
                TreeNode* r=q.front();
                q.pop();
                if(!r) continue;
                if(flag) ans.push_back(r->val);
                flag=false;
                if(r->right) q.push(r->right);
                if(r->left) q.push(r->left);
            }
        }
        return ans;
    }
};