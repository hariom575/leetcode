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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt=1;
        ListNode * temp=head;
        ListNode * prev=NULL;
        while(cnt<left){
            prev=temp;
            temp=temp->next;
            cnt++;
        }
      ///  cout<<temp->val<<" "<<prev->val<<" ";
        ListNode* temp1=temp;
        ListNode* prev1=NULL;
        ListNode* next=NULL;
        while(cnt<=right){
            next=temp->next;
            temp->next=prev1;
            prev1=temp;
            temp=next;
            cnt++;
        }
       if(temp1) temp1->next=temp;
        if(!prev) return prev1;
       if(prev) prev->next=prev1;
       return head;
    }
};