class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        do
        {
            if(fast==nullptr || fast->next==nullptr)
                return nullptr;
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};