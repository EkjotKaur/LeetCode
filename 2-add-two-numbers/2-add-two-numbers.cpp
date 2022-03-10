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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=l1, *q=l2, *r=NULL;
        int c=0;
        while(p && q)
        {
            int x=p->val+q->val+c;
            p->val=x%10;
            r=p;
            p=p->next;
            q=q->next;
            c=x/10;
        }
        while(p)
        {
            int x=p->val+c;
            p->val=x%10;
            r=p;
            p=p->next;
            c=x/10;
        }
        while(q)
        {
            int x=q->val+c;
            ListNode *t=new ListNode;
            t->val=x%10;
            r->next=t;
            r=r->next;
            q=q->next;
            c=x/10;
        }
        if(c)
        {
            
            ListNode *t=new ListNode;
            t->val=c;
            r->next=t;
        }
        return l1;
    }
};