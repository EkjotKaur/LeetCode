class Solution {
//     unordered_map<string,bool>g;
//     int ans;
//     void f(string s, string s1, string s2, int p, int q, vector<int>&dL, vector<int>&dR, int i, int j)
//     {
//         if(s1+s2==s && g[s1]==0)
//         {
//             ans++;
//             g[s1]=1;
//             return;
//         }
//         else if(i>=s.length() || j<0 || i>=j)
//             return;
//         if(p==q)
//         {
//             f(s, s1+s[i], s2, dL[i], q, dL, dR, i+1, j);
//             f(s, s1, s[j]+s2, p, dR[j], dL, dR, i, j-1);
//         }
//         else if(p<q)
//         {
//             f(s, s1+s[i], s2, dL[i], q, dL, dR, i+1, j);
//         }
//         else
//         {
//             f(s, s1, s[j]+s2, p, dR[j], dL, dR, i, j-1);
//         }
        
        
//     }
public:
    int numSplits(string s) {
       int ans=0;
        unordered_map<char,int>h;
        unordered_map<char,int>g;
        
        int n=s.length();
        vector<int>dL(n);
        vector<int>dR(n);
        h[s[0]]++;
        dL[0]=1;
        for(int i=1; i<n; i++)
        {
            h[s[i]]++;
            if(h[s[i]]==1)
                dL[i]=dL[i-1]+1;
            else
                dL[i]=dL[i-1];
            // cout<<dL[i]<<" ";
        }
        
        // h.clear();
        
        g[s[n-1]]++;
        dR[n-1]=1;
        for(int i=n-2; i>=0; i--)
        {
            
            g[s[i]]++;
            // cout<<s[i]<<" "<<g[s[i]]<<dR[i+1]<<"  ";
            if(g[s[i]]==1)
                dR[i]=dR[i+1]+1;
            else
                dR[i]=dR[i+1];
            // cout<<dR[i]<<" ";
        }
        
        
        
        for(int i=0; i<n-1; i++)
        {
            if(dL[i]==dR[i+1])
                ans++;
        }
        
        return ans;
    }
};