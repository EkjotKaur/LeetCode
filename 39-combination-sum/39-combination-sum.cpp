class Solution {
    int n;
    vector<vector<int>>A;
    void backTracking(vector<int>& nums, int target, vector<int>curr, int k)
    {
        if(target==0)
        {
            A.push_back(curr);
            return;
        }
        for(int i=k; i<n && target-nums[i]>=0; i++)
        {
            curr.push_back(nums[i]);
            backTracking(nums, target-nums[i], curr, i);
            curr.pop_back();

        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        backTracking(nums, target, {}, 0);
        return A;
    }
};