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
    int sumRootToLeaf(TreeNode* root) {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int sum = 0;
        vector<int>v;
        dfs(root,sum,v);
        return sum;
    }
    int bitsToDecimal(vector<int> bits){
        int sum = 0;
        int power = 0;
        for(int i=bits.size()-1;i>=0;i--){
            sum += bits[i]*pow(2,power++);
        }
        return sum;
    }
    void dfs(TreeNode* root,int& sum,vector<int> bits){
        if(!root) return;
        bits.push_back(root->val);
        dfs(root->left,sum,bits);
        dfs(root->right,sum,bits);
        if(!root->left && !root->right){
            sum += bitsToDecimal(bits);
            bits.clear();
        }
        root = NULL;
    }
};