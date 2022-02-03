class Solution {
    int dfs(vector<vector<int>>& graph, vector<int>&color, bool c, int i)
    {
        color[i]=c;
        for(auto j:graph[i])
        {
            if(color[j]==-1) 
            {
                color[j]=!c;
                if(!dfs(graph, color, color[j], j))
                    return 0;
            }
            else if(color[j]==c) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>V(n, -1);
        
        for(int i=0; i<n; i++) if(V[i]==-1 && !dfs(graph, V, 0, i)) return 0;
        return 1;
    }
};