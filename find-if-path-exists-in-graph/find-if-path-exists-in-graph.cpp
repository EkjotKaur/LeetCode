class Solution {
    int e;
    void dfs(vector<vector<int>>& G, int i, vector<int>&V)
    {
        V[i]=1;
        if(i==e)
            return;
        for(int j=0; j<G[i].size(); j++)
        {
            if(!V[G[i][j]])
                dfs(G, G[i][j], V);
        }
    }   
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>>G(n);
        e=end;
        for(int i=0; i<edges.size(); i++)
        {
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>V(n);
        
        dfs(G, start, V);
        
        return V[end];
        
        
    }
};