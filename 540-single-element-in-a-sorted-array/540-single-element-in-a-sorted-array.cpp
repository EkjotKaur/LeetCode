class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int x = 0;
        for(auto c:nums) x^=c;
        return x;
    }
};