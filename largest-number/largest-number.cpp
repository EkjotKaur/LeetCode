class Solution {

    
    bool comparefn(string a, string b)
    {
        return (a+b > b+a);
    }
 
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string>N;
        for(int i=0; i<nums.size(); i++)
        {
            N.push_back(to_string(nums[i]));
        }
        
        // sort(N.begin(), N.end(), cmp);
        // sort(N.begin(), N.end(), comparefn);
        
        sort(N.begin(), N.end(), [this] (string a, string b) {
    return comparefn(a, b); });

        
        string s="";
        for(auto c:N)
        {
            s+=c;
        }
        
        if(s[0]=='0') return "0";
        return s;
    }
};