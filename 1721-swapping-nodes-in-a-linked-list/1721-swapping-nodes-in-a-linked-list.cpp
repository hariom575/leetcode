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
    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        ListNode *node1;
        ListNode *node2;
        temp=head;
        int klast=len-k+1;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            if(cnt==k) node1=temp;
            if(cnt==klast) node2=temp;
            temp=temp->next;
        }
     //    k=*node2;
        cout<<k;
        swap(node1->val,node2->val);
        return head;
    }
};