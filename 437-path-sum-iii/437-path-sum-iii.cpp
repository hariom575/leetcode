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
    void dfs(TreeNode * root,long long int cur,int sum,long long int &cnt){
     if(!root){
         return;
     }
    cur+=root->val;
    if(cur==sum)cnt++;
    dfs(root->left,cur,sum,cnt);
    dfs(root->right,cur,sum,cnt);
    }
    int pathSum(TreeNode* root, int targetSum) {
      queue<TreeNode *> q;
     q.push(root);
      long long int cnt=0;
      while(!q.empty()){
          int sz=q.size();
          while(sz--){
              TreeNode * node= q.front();
              q.pop();
              if(!root) continue;
              dfs(node,0,targetSum,cnt);
              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);
        }
      }
        return cnt;
    }
};