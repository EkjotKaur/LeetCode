class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int flag=0;
        for(int i=n-1; i>0; i--)
        {
            if(nums[i]>nums[i-1])
            {
                int x=nums[i-1];
                int k=i;
                int y=INT_MAX;
                for(int j=i; j<n; j++)
                {
                    if(nums[j]>x && y>nums[j])
                    {
                        k=j;
                        y=nums[j];
                    }
                }
                swap(nums[k], nums[i-1]);
                sort(nums.begin()+i, nums.end());
                flag=1;
                break;
            }
           
        }
        
        if(!flag) reverse(nums.begin(), nums.end());
        
        
        
    }
};