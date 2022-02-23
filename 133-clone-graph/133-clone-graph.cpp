/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node * node, Node *copy,map<int ,Node*>&m){
        m[node->val]=copy;
        for(auto child:node->neighbors){
            if(m[child->val]==NULL){
        Node *c =new Node(child->val);
                copy->neighbors.push_back(c);
                m[child->val]=c;
                dfs(child,c,m);
                
}
            else{
                copy->neighbors.push_back(m[child->val]);
}
}
    }
    Node* cloneGraph(Node* node) {
        map<int,Node *>m;
        if(node==NULL) return node;
        Node *copy =new Node(node->val);
    m[node->val]=copy;
        for(auto child:node->neighbors){
            if(m[child->val]==NULL){
        Node *c =new Node(child->val);
                copy->neighbors.push_back(c);
                m[child->val]=c;
                dfs(child,c,m);
                
}
            else{
                copy->neighbors.push_back(m[child->val]);
}
}
        return copy;
        
    }
};