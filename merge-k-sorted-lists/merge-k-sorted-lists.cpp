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
    ListNode *mergeTwo(ListNode* l1, ListNode *l2)
    {
        ListNode *head;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
         if(l1->val <= l2->val)
        {
            head = l1;
            l1=l1->next;
             
        }
        else
        {
            head=l2;
            l2=l2->next;
        }
        head->next=NULL;
        ListNode *p=head;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                p->next=l1;
                l1=l1->next;
            }
            else
            {
                p->next=l2;
                l2=l2->next;
            }
            
            p=p->next;
            p->next=NULL;
        }
        if(l1)
            p->next=l1;
        if(l2)
            p->next=l2;
        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        ListNode *l3=mergeTwo(lists[0], lists[1]);
        for(int i=2; i<n; i++){
            l3=mergeTwo(l3, lists[i]);
        }
        
        return l3;
    }
};