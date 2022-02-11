class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       if(s1.size()>s2.size())
           return 0;
        vector<int>h(26);
        vector<int>g(26);
        for(int i=0; i<s1.size(); i++)
        {
            cout<<s1[i]-'a'<<" ";
            h[s1[i]-'a']++;
            g[s2[i]-'a']++;
        }
        if(h==g)
            return 1;
        int j=0;
        for(int i=s1.size(); i<s2.size(); i++)
        {
            g[s2[i]-'a']++;
            g[s2[j]-'a']--;
            if(h==g)
                return 1;
            j++;
        }
        return 0;
    }
};