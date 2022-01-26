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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>s1, s2; //stack for inorder traversal
        vector<int>ans;
        if(root1 == nullptr && root2 == nullptr)
            return ans;
        TreeNode *r1 = root1, *r2 = root2;
        int x, y;
        while(!s1.empty() || !s2.empty() || r1 != nullptr || r2 != nullptr)
        {
            while(r1 != nullptr)
            {
                s1.push(r1);
                r1 = r1->left;
            }
            while(r2 != nullptr)
            {
                s2.push(r2);
                r2 = r2->left;
            }
			// top of the stack will have smallest node currently not processed in the BST
            x = (!s1.empty()) ? s1.top()->val : INT_MAX;
            y = (!s2.empty()) ? s2.top()->val : INT_MAX;
            //cout<<x<<" "<<y<<"\n";
			// Now compare values and merge while traversing
            if(x < y)
            {
                ans.push_back(x);
                r1 = s1.top()->right;
                s1.pop();
            }
            else
            {
                ans.push_back(y);
                r2 = s2.top()->right;
                s2.pop();
            }
        }
        return ans;
    }
};