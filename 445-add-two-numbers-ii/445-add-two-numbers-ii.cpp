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
    ListNode* reverse(ListNode* head){
    ListNode* curr = head, *prev = NULL, *next = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    int carry = 0;
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    while(l1 or l2 or carry){
        int sum = 0;
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum+= l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum/10;
        ListNode* fresh = new ListNode(sum%10);
        temp->next = fresh;
        temp = temp->next;            
    }
    return reverse(dummy->next);
}
};