class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     map<int,int>h;
        for(int i=0; i<nums.size(); i++)
        {
            if(h[nums[i]]==0)
                h[nums[i]]++;
            else
                return nums[i];
        }
        return 0;
    }
};