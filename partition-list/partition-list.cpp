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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small=NULL, *s=NULL;
        ListNode *large=NULL, *l=NULL;
        
        ListNode *p=head;
       
        while(p)
        {
            if(p->val<x)
            {
                if(!s)
                {
                    s=p;
                    small=s;
                }
                else
                {
                    s->next=p;
                    s=s->next;
                }
            }
            else 
            {
                if(!l)
                {
                    l=p;
                    large=l;
                }
                else
                {
                    l->next=p;
                    l=l->next;
                }
            }   
            p=p->next;
            
        }
        
       if(s) s->next=large;
        if(l) l->next=NULL;
        
        return small?small:large;
        

    }
};