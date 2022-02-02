class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>h(26,0);
        vector<int>g(26,0);
        int n=s.length(),m=p.length();
        for(auto i:p) h[i-'a']++;
        vector<int>A;
        for(int i=0; i<n; i++)
        {
            g[s[i]-'a']++;
            if(i>=m) g[s[i-m]-'a']--;
            if(g==h) A.emplace_back(i-m+1);   
        }
        return A;
    }
};