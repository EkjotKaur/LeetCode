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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *t=head;
        if(!t) return head;
        int x=101;
        
        while(t)
        {
            if(t->next && t==head && t->next->val==t->val)
            {
                x=t->val;
                head=t->next->next;
                t=head;
            }
            else if(t==head && t->val==x)
            {
                head=t->next;
                t=head;
            }
            else if(t->next && t->next->next && t->next->val==t->next->next->val)
            {
                x=t->next->val;
                // if(t==head)
                t->next=t->next->next->next;
            }
            else if(t->next && t->next->val==x)
                t->next=t->next->next;
            else
            {   
                x=101;
                t=t->next;
            }
        }
        
        return head;
    }
};