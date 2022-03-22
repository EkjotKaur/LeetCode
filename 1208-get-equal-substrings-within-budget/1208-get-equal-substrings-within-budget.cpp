class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n=s.length();
        vector<int>h(n);
        for(int i=0; i<n; i++)
            h[i]=abs(s[i]-t[i]);
        
        int ans=INT_MIN, cost=maxCost,len=0;
        for(int i=0,j=0; i<n; i++)
        {
            while(j<=i && cost-h[i]<0)
            {
                cost+=h[j];
                j++;
                len--;
            }
            cost-=h[i];
            len++;
            ans=max(len,ans);
        }
        
        return ans;
    }
};