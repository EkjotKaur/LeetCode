class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>h(26);
        vector<bool>v(26,0);
        
        for(auto i:s)
            h[i-'a']++;
        
        string ans="";
        for(auto i:s)
        {
            if(v[i-'a']) {h[i-'a']--;continue;}
            while(!ans.empty() && ans.back()>i && h[ans.back()-'a']>0)
            {
                v[ans.back()-'a']=0;
                ans.pop_back();
            }
            h[i-'a']--;
            v[i-'a']=1;
            ans+=i;
        }
        
        return ans;
        
    }
};