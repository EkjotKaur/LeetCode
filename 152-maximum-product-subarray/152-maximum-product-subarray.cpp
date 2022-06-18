class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x = nums[0], y = nums[0],total=nums[0], n=nums.size();
        
        for(int i=1; i<n; i++)
        {
            if(nums[i]>0)
            {
                y = max(nums[i],y*nums[i]);
                x = min(nums[i],x*nums[i]);
            }
            else if(nums[i]<0)
            {
                int z = x;
                x = min(nums[i],y*nums[i]);
                y = max(nums[i],z*nums[i]);
            }
            else 
            {
                y=0;
                x=0;
            }
            
            // cout<<x<<" "<<y<<"\n";
            total=max(total, y);
        }
        
        return total;
    }
};