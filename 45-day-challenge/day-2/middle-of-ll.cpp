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
    ListNode* solve(ListNode*head)
    {
        if(!head)
         return NULL;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next )
        {
            slow=slow->next;
            fast=fast->next;
            if(fast->next)
             fast=fast->next;
        }
        return slow;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode*middle=solve(head);
        return middle;
    }
};