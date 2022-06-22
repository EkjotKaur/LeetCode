/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>A;
        if(!root) return A;
        queue<pair<Node *, int>>Q;
        Q.push({root, 0});
        int level = -1;
        while(!Q.empty())
        {
            pair<Node*,int>p = Q.front();
            Q.pop();
            if(level != p.second)
            {
                A.push_back({p.first->val});
                level++;
            }
            else 
                A.back().push_back(p.first->val);
            
            for(auto x: p.first->children)
                Q.push({x, p.second+1});
        }
        
        return A;
        
    }
};