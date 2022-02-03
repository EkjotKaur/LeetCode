class Solution {
    void dfs(vector<vector<int>>& graph, int i, vector<int>&V)
    {
        V[i]=0;
                
        for(auto j:graph[i])
        {
            if(V[j]==-1)
            {
                dfs(graph, j, V);
            }
            if(V[j]==0) return;
        }
        V[i]=1;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<int>V(n, -1);
        
        for(int i=0; i<n; i++)
        {
            if(V[i]==-1) dfs(graph, i, V);
            if(V[i]==1) ans.emplace_back(i);
        }
        
        
        return ans;
    }
};