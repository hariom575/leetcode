/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    

    void getParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp){
      
        mp[root]=NULL;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left!=NULL){
                
                mp[node->left]=node;
                q.push(node->left);
                
            }
            
            if(node->right!=NULL){
                
                mp[node->right]=node;
                q.push(node->right);
                
            }
            
            
        } 
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        
        if(root==NULL)return {};
        
        unordered_map<TreeNode*,bool>vis;
        
        unordered_map<TreeNode*, TreeNode*>par;
        
        getParent(root,par);
        
        queue<pair<TreeNode*,int>>q;
        
        vector<int>ans;
        
        q.push({target,0});
        vis[target]=true;
		
        while(!q.empty()){
                
            auto it = q.front();
            q.pop();

            TreeNode *node = it.first;
            int dis = it.second;   

            if(dis==k)ans.push_back(node->val);

            if(node->left !=NULL && vis[node->left]==false){

                vis[node->left]=true;
                q.push({node->left,dis+1});

            }

            if(node->right !=NULL && vis[node->right]==false){

                vis[node->right]=true;
                q.push({node->right,dis+1});

            }

            if(par[node] !=NULL && vis[par[node]]==false){

                vis[par[node]]=true;
                q.push({par[node],dis+1});
            }
                    
        }

        
        return ans;
    
        
    }
};