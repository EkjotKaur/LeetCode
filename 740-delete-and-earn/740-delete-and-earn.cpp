class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int>h(n);
        for(auto c:nums)
        {
            h[c]+=c;
        }
        
        int take=0,skip=0;
         for(int i=0; i<n; i++)
         {
             int t=skip+h[i];
             int s=max(take,skip);
             take=t;
             skip=s;
         }
            
        return max(skip,take);
     
    }
};