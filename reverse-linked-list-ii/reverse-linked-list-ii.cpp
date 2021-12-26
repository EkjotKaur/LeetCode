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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=1;
        ListNode *p=head,*q=NULL;
        while(i<left)
        {
            q=p;
            p=p->next;
            i++;
        }
        
        ListNode *Ln = q, *start = p;
        
        while(i<right && p)
        {
            p=p->next;
            i++;
        }
        
        ListNode *end = p, *Rn = p->next;
        
        
        p=start;
        q=NULL;
        ListNode *r=NULL;
        while(p!=Rn)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        
        if(Ln)
            Ln->next = end;
        else
            head=end;
        
        start->next=Rn;
        
        return head;
        
    }
};