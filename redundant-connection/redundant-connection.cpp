class Solution {
    bool bfs(vector<vector<int>>&G, vector<int>&V, int i, int par = -1)
    {
        if(V[i]) return 1;
        V[i]=1;
        for(int j=0; j<G[i].size(); j++)
        {
            if(par!=G[i][j] && bfs(G, V, G[i][j], i)) return 1;
            
        }
        return 0;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>G(n+1);
       
        
        for(int i=0; i<n; i++)
        {
            vector<int>V(n+1);
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]);
            if(bfs(G, V, edges[i][0])) return  edges[i];
        }
        
        return {-1};
    }
};