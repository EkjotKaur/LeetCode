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
    int v;
    void f(TreeNode* root, int big, int small)
    {
        if(!root) return;
        big=max(big, root->val);
        small=min(small, root->val);
        
        v=max(v,big-small);
        f(root->left, big, small);
        f(root->right, big, small);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        v=0;
        f(root, INT_MIN, INT_MAX);
        return v;
    }
};