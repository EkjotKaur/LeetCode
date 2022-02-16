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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p=head,*q=head->next,*r=NULL;
        
        while(p && q)
        {
            p->next=q->next;
            q->next=p;
            if(r)
            {
                r->next=q;
            }
            else
            {
                head=q;
            }
            r=p;
            p=p->next;
            if(p)
            {
                q=q->next->next->next;
            }
            
        }
        
        return head;
    }
};