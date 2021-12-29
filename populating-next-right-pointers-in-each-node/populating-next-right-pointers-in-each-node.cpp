/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        Node *p=root,*q=NULL;
        while(p)
        {   
            q=p;
            if(p->left)
            {
                p->left->next=p->right;
                // cout<<p->left->next<<" ";
                // cout<<p->right->val<<" ";
            }
            while(q->next)
            {
              
                if(q->right)
                {
                    q->right->next=q->next->left;
                }
                q=q->next;
                if(q->left)
                {
                    q->left->next=q->right;
                }

            }

            p=p->left;
        }
        return root;
        
    }
};