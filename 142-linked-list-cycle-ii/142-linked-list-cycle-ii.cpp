/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *, ListNode *>h;
        if(!head) return NULL;
        ListNode* p=head;
        h[head]=NULL;

        while(p && p->next)
        {
            // cout<<p;
            if(h.find(p->next)!=h.end())
            {
                
                if(h[p->next]!=p) return p->next;
            }
            else
            {
                h[p->next]=p;
            }
            p=p->next;
                
        }
        return NULL;
    }
};