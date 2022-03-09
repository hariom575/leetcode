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
   ListNode* deleteDuplicates(ListNode* head) {
if(!head or !head->next)
return head;
ListNode *curr = head,*prev = NULL;
while(curr)
{
if(curr->next and curr->next->val == curr->val)
{
int val = curr->val;
while(curr and curr->val == val)
{
curr = curr->next;
}
if(prev==NULL)
{
head = curr;
}
else
{
prev->next = curr;
}
}
else
{
prev = curr;
curr = curr->next;
}
}
return head;
}
};