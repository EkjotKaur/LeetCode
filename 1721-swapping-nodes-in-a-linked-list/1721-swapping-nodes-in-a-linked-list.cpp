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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode *p=head;
        while(p)
        {
            n++;
            p=p->next;
        }
        
        int l=n-k+1;
        
        ListNode *r,*q;
        r=q=NULL;
        p=head;
        int i=0;
        while(p)
        {
            i++;
            if(i==k)
                r=p;
            if(i==l)
                q=p;
            p=p->next;
        }
        
        swap(r->val,q->val);
        return head;
    }
};