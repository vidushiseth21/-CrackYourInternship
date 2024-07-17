class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
         return nullptr;
            while(head && head->val==val)
            {
                ListNode*temp=head;
                head=head->next;
                delete(temp); 
            }
        ListNode*p=head;
        while(p && p->next)
        {
            if(p->next->val==val)
            {
               ListNode*temp=p->next;
               p->next=temp->next;
               delete(temp);
            }
            else
            {
                p=p->next;
            }
        }
        return head;
    }
};
