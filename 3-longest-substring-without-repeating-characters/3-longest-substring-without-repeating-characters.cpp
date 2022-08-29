class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        unordered_map<int,int>h;
        int c = 0, ans = 0, j = 0;
        for(int i=0; i<n; i++)
        {
            // cout<<h[s[i]]<<" ";
            if(h.find(s[i])==h.end() || h[s[i]]==0)
            {
                c++;
            }
            else
            {
                while(s[j]!=s[i])
                {
                    c--;
                    h[s[j]]=0;
                    j++;
                }
                j++;
            }
            h[s[i]]=1;
            ans = max(ans, c);
            // cout<<c<<" ";
        }
        
        return ans;
    }
};