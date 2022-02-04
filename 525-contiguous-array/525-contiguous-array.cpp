class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int ans=0, n=nums.size();
        unordered_map<int,pair<int,int>>h;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            count = nums[i]==1 ? count+1 : count-1;
            if(h.find(count)==h.end()) h[count]={i,-1};
            else h[count].second=i;
            if(count==0) ans=max(ans, i+1);
        }
        
        for(auto i:h)
        {
            // cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";
            if(i.second.second!=-1) ans=max(ans, i.second.second-i.second.first);
        }
        return ans;
    } 
};