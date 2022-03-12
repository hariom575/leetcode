/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        ListNode*temp=head;
        if(head==NULL) return head;
        ListNode* last=NULL;
        while(temp!=NULL){
            if(temp->next==NULL) last=temp;
            temp=temp->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;
        int l=len-k;
        temp=head;
        last->next=head;
        ListNode *prev=NULL;
        for(int i=1;i<=l;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        return temp;
    }
};