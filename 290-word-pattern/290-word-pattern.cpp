class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string>h;
        map<string,char>g;
        
        string t="";
        vector<string>ST;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==' ')
            {
                ST.push_back(t);
                t="";
            }
            else
            {
                t+=s[i];
            }
        }
        ST.push_back(t);
        if(pattern.length() != ST.size()) return 0;
        
        for(int i=0; i<pattern.length(); i++)
        {
            if(h.find(pattern[i])!=h.end())
            {
                // cout<<pattern[i]<<ST[i]<<" ";
                if(h[pattern[i]]!=ST[i])
                    return 0;
            }
            else if(g.find(ST[i])!=g.end())
            {
                if(g[ST[i]]!=pattern[i])
                    return 0;
            }
            else
            {
                h[pattern[i]]=ST[i];
                g[ST[i]]=pattern[i];
            }
        }
        return 1;
    }
};