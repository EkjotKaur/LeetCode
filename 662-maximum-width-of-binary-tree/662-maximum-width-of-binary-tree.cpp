/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        unsigned long long int x = 1073741824;
        x*=2;
        queue<TreeNode*>Q;
        queue<pair<unsigned long long,unsigned long long>>P;
        // vector<pair<int,vector<TreeNode*>>>ans;
        
        vector<pair<unsigned long long,unsigned long long>>ans;
        Q.push(root);
        P.push({0,0});
        int level=-1;
        
        while(!Q.empty())
        {
            TreeNode *node = Q.front();
            Q.pop();
            int l = P.front().first;
            int pos = P.front().second;
            P.pop();
            // cout<<node->val<<" "<<pos<<"  ";
            
            if(l!=level)
            {
                level=l;
                ans.push_back({pos,pos});
                // ans.push_back({1,{node}});
            }
            else 
            {
                ans.back().second=pos;
            }
            
            if(!node) continue;
          
            if(node->left)
            {
                Q.push(node->left);
                P.push({l+1, (long long) 2*pos});
            }
            if(node->right)
            {
                Q.push(node->right);
                P.push({l+1, (long long) 2*pos+1});
            }
              
        }
        
        unsigned long long mx=0;
        for(int i=0; i<ans.size(); i++)
        {
            mx=max(mx, ans[i].second-ans[i].first+1);
        }
        
        // sort(ans.begin(), ans.end());
        return mx;
    }
};