class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int ans=0, n=nums.size(), dif=INT_MAX;
        for(int i=0; i<n-2; i++)
        {
            int x = target-nums[i];
            
            int j=i+1,k=n-1;

            while(j<k)
            {
                // cout<<nums[j]<<" "<<nums[k]<<" ";
                // cout<<dif<<" "<<abs(x-(nums[j]+nums[k]))<<" "<<x<<"  ";
                if(dif>abs(x-(nums[j]+nums[k])))
                {
                    ans=nums[i]+nums[j]+nums[k];
                    dif=abs(x-(nums[j]+nums[k]));
                }
                if(nums[j]+nums[k]<=x)
                {
                    j++;
                }
                else 
                {
                    k--;
                }
            }
        }
        
        return ans;
    }
};