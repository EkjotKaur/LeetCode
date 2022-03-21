class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>g;
        
        for(int i=0; i<s.length(); i++)
        {
            g[s[i]]=i;
        }
        
        int start=0,end=0;
        vector<int>A;
        for(int i=0; i<s.length(); i++)
        {
            if(end<i)
            {
                A.push_back(end-start+1);
                start=i;
                end=i;
            }
            if(g[s[i]]>end)
                end=g[s[i]];
            
        }
        A.push_back(end-start+1);
        return A;
    }
};