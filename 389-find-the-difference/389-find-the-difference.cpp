class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int,int>h;
        for(auto c:s) h[c]++;
        for(auto c:t)
        {
            h[c]--;
            if(h[c]<0) return c;
        }
        return '-1';
    }
};