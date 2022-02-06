class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        int n=1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1]==nums[i])
            {
                n++;
                if(n<3)
                    nums[j++]=nums[i];
            }
            else
            {
                n=1;
                nums[j++]=nums[i];
            }
        }
        
        return j;
    }
};