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
    ListNode* reverse(ListNode * head){
        ListNode *prev=NULL,*cur=head,*next=NULL;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
     if(!head || !head->next) return true;
      ListNode *fast=head->next,*slow=head;
     while(fast and fast->next){
         fast=fast->next->next;
         slow=slow->next;
     }
     ListNode *second=slow->next;
     ListNode * first=head;
     slow->next=NULL;
     second=reverse(second);
        while(second){
            if(second->val!=first->val) return false;
            second=second->next;
            first=first->next;
        }
        return true;
    }
};