class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr)
            return nullptr;
        ListNode* p=nullptr;
        ListNode* q=head;
        ListNode* r=head->next;
        ListNode* t1;
        ListNode* t2;
        
        if(m==n)
            return head;
        else if(m==1)
        {
            for(int i=0;i<n;i++)
            {
                q->next=p;
                p=q;
                q=r;
                if(r==nullptr)
                    break;
                r=r->next;
            }
            head->next=q;
            return p;
        }
        for(int i=0;i<m;i++)
        {
            if(i==m-1)
                t2=p;
            p=q;
            q=r;
            r=r->next;
        }
        t1=p;
        t2->next=nullptr;
        t1->next=nullptr;
        for(int i=0;i<n-m;i++)
        {   
            q->next=p;
            p=q;
            q=r;
            if(r==nullptr)
                break;
            r=r->next;
        }
        t2->next=p;
        t1->next=q;
        
        return head;
    }
};