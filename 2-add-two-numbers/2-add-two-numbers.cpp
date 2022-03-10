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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);
        ListNode* temp=head;
        int r=0;
        int d=0;
        while(l1!=nullptr and l2!=nullptr){
          int x=l1->val+l2->val+r;
        ListNode *t=new ListNode(0);
            r=x/10;
           t->val=x%10;
            temp->next=t;
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }
          while(l1!=nullptr){
          int x=l1->val+r;
        ListNode *t=new ListNode(0);
            r=x/10;
           t->val=x%10;
            temp->next=t;
            temp=temp->next;
                l1=l1->next;
        }
          while(l2!=nullptr){
          int x=l2->val+r;
        ListNode *t=new ListNode(0);
            r=x/10;
           t->val=x%10;
            temp->next=t;
            temp=temp->next;
                l2=l2->next;
        }
        if(r){
             ListNode *t=new ListNode(0);
           t->val=r;
            temp->next=t;
            temp=temp->next;
        }
        temp->next=NULL;
        return head->next;
    }
};