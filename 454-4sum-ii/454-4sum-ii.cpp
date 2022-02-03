class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int>h;
        
        int ans=0;
        for(auto i:nums1) 
            for(auto j:nums2)
                h[i+j]++;
        
        for(auto j:nums3)
            for(auto k:nums4)
                if(h[-(j+k)]!=0) ans+=h[-(j+k)];
        return ans;
    }
};