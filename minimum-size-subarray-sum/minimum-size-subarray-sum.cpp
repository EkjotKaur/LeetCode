class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int ans=0;
        int sum=0;
        int MIN=INT_MAX;
        int n=nums.size();
        for(;i<n && j<n;)
        {
            if(sum<target)
            {
                sum+=nums[j];
                ans++;
                j++;
                if(sum>=target && MIN>ans) MIN=ans;
                    
            }
            else
            {
                sum-=nums[i];
               
                ans--;
                if(MIN>ans && sum>=target)
                    MIN=ans;
                i++;
            }
            // cout<<i<<" "<<j<<" "<<ans<<" "<<sum<<" "<< MIN<<"\n";
            
            
        }
        while(sum-nums[i]>=target && i<n)
        {
            sum-=nums[i];
            i++;
            ans--;
            MIN=min(MIN, ans);
        }
        // if(MIN==INT_MAX && target<=sum) return ans;
        
        return MIN==INT_MAX?0:MIN;
    }
};