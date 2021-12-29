/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node *f(Node *node, unordered_map<Node*, Node *>&V)
    {
        if(!node) return NULL;
        
        Node *g = new Node(node->val);
        V[node]=g;
        
        for(int i=0; i<node->neighbors.size(); i++)
        {
            if(V[node->neighbors[i]]!=NULL)
            {
                g->neighbors.push_back(V[node->neighbors[i]]);
            }
            else
            {
                Node *x = f(node->neighbors[i], V);
                g->neighbors.push_back(x);
            }
        }
        
        return g;
        
    }
public:
    Node* cloneGraph(Node* node) {
       
        unordered_map<Node*, Node*>V;
        
        
        return f(node, V);
        
    }
};