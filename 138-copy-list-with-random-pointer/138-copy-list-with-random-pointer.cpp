/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *>h;
        
        Node *p=head;
        Node *q=NULL;
        Node *H= NULL;
        while(p)
        {
            
            // Node *t= new Node;
            // t->val=p->val;
            // if(!H) H=t;
            // if(q) q->next=t;
            // q=t;
            // h[p->]
            // p=p->next;
            if(h.find(p) != h.end() && q)
            {
                q->next=h[p];
                q=q->next;
            }
            else
            {
                Node *t= new Node(p->val);
                h[p]=t;
                if(!H) H=t;
                if(q) q->next=t;
                q=t;      
            }
            if(p->random && h.find(p->random) != h.end())
            {
                q->random=h[p->random];
                // cout<<h[p->next]->val;
            }
            else if(p->random)
            {
                Node *t= new Node(p->random->val);
                q->random=t;
                h[p->random]=t;
            }
            p=p->next;
        }
        
        return H;          
              
    }
};