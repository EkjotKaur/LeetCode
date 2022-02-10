class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0, sum=0;
        unordered_map<int,int>h;
        h[0]=1;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            if(h.find(sum-k)!=h.end())
                ans+=h[sum-k];
            h[sum]++;
           
        }
        return ans;
        
    }
};