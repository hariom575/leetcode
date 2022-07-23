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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* nex = NULL;
        ListNode* curr = head;
        while(curr)
        {
            nex = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;
        if(!second)return;
        while(second && second->next)
        {
            first = first->next;
            second = second->next->next;
        }
        second = first->next;
        first->next = NULL;
        second = reverse(second);
        
        first = head;
        while(first)
        {
            auto temp = first->next;
            first->next = second;
            auto temp1 = second!= NULL?second->next:second;
            if(second)
            {
              second->next = temp;

            }
            first = temp;
            second = temp1;
            
        }
        
    }
};