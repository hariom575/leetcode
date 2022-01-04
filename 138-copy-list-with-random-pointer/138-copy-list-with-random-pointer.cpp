/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *head1=new Node(-1);
        map<Node*,Node*>mp;
        Node *temp=head;
        Node *temp1=head1;
        while(temp){
            Node* newNode= new Node(temp->val);
            mp[temp]=newNode;
            temp1->next=newNode;
            temp1=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node *res= mp[temp];
            if(!temp->random) res->random=NULL;
            else res->random=mp[temp->random];
            temp=temp->next;
        }
        return head1->next;
    }
};