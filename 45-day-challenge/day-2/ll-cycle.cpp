/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   bool middle(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head->next;  
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast->next)
              fast=fast->next;
            if(slow==fast)
             return true;
        }
        return false;

    }
    bool hasCycle(ListNode *head) {
        if(!head  || !head->next)
         return false;
        return middle(head);
    }
};