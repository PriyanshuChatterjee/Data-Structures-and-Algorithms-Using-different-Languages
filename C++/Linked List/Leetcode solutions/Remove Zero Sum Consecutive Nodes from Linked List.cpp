class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        int sum=0;
        ListNode* t=head;
        while(t)
        {
            sum+=t->val;
            if(!sum)
            {
                head=t->next;
                mp.clear();
            }
            else
            {
                if(mp.find(sum)!=mp.end())
                {
                    int prevSum=sum;
                    ListNode* dltStrt=mp[sum]->next;
                    while(dltStrt!=t)
                    {
                        prevSum+=dltStrt->val;
                        mp.erase(prevSum);
                        dltStrt=dltStrt->next;
                    }
                    mp[sum]->next=t->next;
                }
                else
                    mp[sum]=t;
            }
            t=t->next;
        }
        return head;
    }
};