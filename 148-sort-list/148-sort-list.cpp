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
    ListNode *merge(ListNode *L1, ListNode *L2)
    {
        if(!L1) return L2;
        if(!L2) return L1;
        ListNode *head=NULL;
        if(L1->val<=L2->val)
        {
            head=L1;
            L1=L1->next;
        }
        else
        {
            head=L2;
            L2=L2->next;
        }
        head->next=NULL;
        ListNode *p=head;
        while(L1 && L2)
        {
            if(L1->val<=L2->val)
            {
                p->next=L1;
                p=L1;
                L1=L1->next;
            }
            else
            {
                p->next=L2;
                p=L2;
                L2=L2->next;
            }
            p->next=NULL;
        }
        if(L1) p->next=L1;
        if(L2) p->next=L2;
        
        
        return head;
    }
    ListNode *mergeSort(ListNode *head, int n)
    {
        if(!head) return head;
        if(n==1) return head;
        
        int m=n/2,i=0;
        ListNode *p = head, *r=NULL;
        while(i<m)
        {
            r=p;
            p=p->next;
            i++;
        }
        
        r->next=NULL;
        ListNode *x = mergeSort(head, n/2);
        ListNode *y = mergeSort(p, (n+1)/2);
      
        return merge(x,y);
 
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode *p = head;
        int n=0;
        while(p)
        {
            p=p->next;
            n++;
        }
        return mergeSort(head, n);
    }
};