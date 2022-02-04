class Solution {
    bool dfs(vector<vector<int>>&G, vector<int>&V, vector<int>&done, int i)
    {
        V[i]=1;
        
        for(auto j:G[i])
        {
            if(!V[j] && !dfs(G, V, done, j)) return 0;
            if(!done[j]) return 0;
        }
        done[i]=1;
        return 1;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>G(n);
        for(auto it:prerequisites)
        {
            G[it[0]].emplace_back(it[1]);
        }
        
        vector<int>V(n);
        vector<int>done(n);
        
        for(int i=0; i<n; i++)
        {
            if(!V[i] && !dfs(G, V, done, i)) return 0;
        }
        
        return 1;
    }
};