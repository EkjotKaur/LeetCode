class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        map<int,int>h;
        map<string, int>g;
        for(int i=0; i<n; i++) h[nums[i]]++;
        vector<vector<int>>A;
        for(auto C:h)
        {
            for(auto F:h)
            {
                int k = 0;
                int c = C.first, f = F.first;
                if(c==f)
                {
                    k++;
                    if(h[c]==1)
                        continue;
                }
                int x = c+f, y = -x;
                vector<int>B;
                if(h.find(y)==h.end()) continue;
                if(y!=c && y!=f)
                {
                    if(h[y]>=1)
                        B = {c, f, y};
                }
                else if(y==c && y==f)
                {
                    if(h[y]>=3)
                        B = {c, f, y};
                }
                else if(y==c || y==f)
                {
                    if(h[y]>=2)
                        B = {c, f, y};
                }
                
                if(!B.empty())
                {
                    sort(B.begin(), B.end());
                    string s = "";
                    for(auto c:B)
                        s+=to_string(c)+"-";
                    if(g.find(s)==g.end())
                    {
                        A.push_back(B);
                        g[s]=1;
                    }
                }
            }
            
            
        }
        return A;
    }
};