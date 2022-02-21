class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>h;
        
        int m=nums.size()/2;
        
        for(auto c:nums)
        {
            h[c]++;
            if(h[c]>m)
                return c;
        }
        
        return -1;
        
    }
};