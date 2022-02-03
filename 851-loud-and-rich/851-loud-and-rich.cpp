class Solution {
    void dfs(vector<vector<int>>&G, vector<pair<int,int>>&V, int i, vector<int>& quiet)
    {
        V[i]={quiet[i],i};
        for(auto u:G[i])
        {
            if(V[u].first==-1)
                dfs(G, V, u, quiet);
            pair<int,int>x=V[u];
            if(x.first<V[i].first) V[i]=x;
        }
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int m=richer.size(), n=quiet.size();
        
        vector<vector<int>>G(n);
        for(auto i:richer)
            G[i[1]].emplace_back(i[0]);
        
        vector<pair<int,int>>value(n, {-1,-1});
        
        for(int i=0; i<n; i++)
            if(value[i].first==-1) dfs(G, value, i, quiet);
        
        vector<int>ans;
        for(auto i:value)
            ans.emplace_back(i.second);
        return ans;
    }
};