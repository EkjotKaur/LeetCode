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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        
        int n=0;
        ListNode* p=head, *t=NULL;;
        while(p)
        {
            t=p;
            p=p->next;
            n++;
        }
        k=k%n;
        if(k==0) return head;
        
        int r=n-k-1;
        // cout<<r<<" ";
        int i=0;
        p=head;
        while(i<r)
        {
            p=p->next;
            // cout<<p->val<<" ";
            i++;
        }
       
        ListNode *q=p->next;
        p->next=NULL;
        t->next=head;
        return q;
    }
};