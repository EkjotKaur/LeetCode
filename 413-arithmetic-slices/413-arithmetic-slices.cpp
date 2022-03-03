class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dif=0,n=nums.size();
        bool empty=1;
        int ans=0,val=0;
        for(int i=1; i<n-1; i++)
        {
            if(empty)
            {
                if(nums[i-1]+nums[i+1]==2*nums[i])
                {
                    dif=nums[i+1]-nums[i];
                    empty=0;
                    val=1;
                }
            }
            else
            {
                if(nums[i+1]-nums[i]==dif)
                {
                    val++;
                }
                else
                {
                    empty=1;
                    ans+=val*(val+1)/2;
                    val=0;
                }
            }
            // cout<<ans<<" "<<val<<" ";
        }
        
        if(!empty) ans+=val*(val+1)/2;
        
        return ans;
    }
};