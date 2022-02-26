class Solution {
    int solve(vector<vector<int>>& graph, int node, int mask, vector<vector<int>>&cache)
    {
        if(cache[node][mask]!=0) return cache[node][mask];
        if((mask & (mask-1)) == 0)
            return 0;
        cache[node][mask]=INT_MAX-1;
        for(auto it:graph[node])
        {
            if((mask & (1<<it)) !=0)
            {
                int alreadyVisited = solve(graph, it, mask, cache);
                int notVisited = solve(graph, it, mask^(1<<node), cache);
                cache[node][mask] = min(cache[node][mask], 1 + min(alreadyVisited, notVisited)); 
            }
        }
        
        
        return cache[node][mask];
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int endingMask = (1<<n)-1;
        vector<vector<int>>cache(n+1, vector<int>(endingMask+1));
        
        int best=INT_MAX;
        for(int i=0; i<n; i++)
        {
            best = min(best, solve(graph, i, endingMask, cache));
        }
        
        return best;
    }
};