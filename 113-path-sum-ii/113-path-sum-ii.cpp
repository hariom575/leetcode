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
    vector<vector<int>> answer;
    void solve(TreeNode *root, vector<int> &ans, int &targetSum, int sum=0){
        if(!root)
            return;
        if(sum+root->val==targetSum && !root->left && !root->right){
            ans.push_back(root->val);
            answer.push_back(ans);
            ans.pop_back();
            return;
        }
        sum+=root->val;
        ans.push_back(root->val);
        solve(root->left, ans, targetSum, sum);
        solve(root->right, ans, targetSum, sum);
        ans.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans={};
        answer={};
        solve(root, ans, targetSum);
        return answer;
    }
};