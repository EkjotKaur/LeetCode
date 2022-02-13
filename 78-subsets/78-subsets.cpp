class Solution {
    int k, n;
    vector<vector<int>>A;
    void backtrack(int first, vector<int>curr, vector<int>& nums)
    {
        if(curr.size()==k)
        {
            A.push_back(curr);
            return;
        }
       
        for(int i=first; i<n; i++)
        {
            curr.push_back(nums[i]);
            backtrack(i+1, curr, nums);
            curr.pop_back();
        }
        
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        n=nums.size();
        
        for(k=0; k<=n; k++)
            backtrack(0, {}, nums);
        return A;
    }
};