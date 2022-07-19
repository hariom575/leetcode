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
class BSTIterator {
public:
    
    void inorder(TreeNode* root, TreeNode* &prev){
        if(root==NULL)
            return;
        
        inorder(root->left, prev);
    
        prev->right=root;
        prev->left=NULL;
        prev=root;
        
        inorder(root->right, prev);
    }
    
    TreeNode* root;
    TreeNode* prev=new TreeNode(INT_MIN);
    TreeNode* start=prev;
    
    BSTIterator(TreeNode* root) {
        this->root=root;
        inorder(root, prev);
        prev->right=NULL;
        prev->left=NULL;
    }
    
    int next() {
        start=start->right;
        return start->val;
    }
    
    bool hasNext() {
        return start->right!=NULL;
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */