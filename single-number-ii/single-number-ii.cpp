class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>h;
        
        for(auto n:nums)
            h[n]++;
        
        for(auto c:h)
        {
            if(c.second==1) return c.first;
        }
        return -1;
    }
};