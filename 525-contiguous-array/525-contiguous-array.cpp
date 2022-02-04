class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int ans=0, n=nums.size();
        unordered_map<int,int>h;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            count = nums[i]==1 ? count+1 : count-1;
            if(h.find(count)==h.end()) h[count]=i;
            else ans=max(ans, i-h[count]);
            if(count==0) ans=max(ans, i+1);
        }
        
        return ans;
    } 
};