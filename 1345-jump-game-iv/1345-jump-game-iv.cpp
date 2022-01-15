class Solution {
    int n;
    int dfs(vector<vector<int>>G, int i, int steps)
    {
        if(i==n-1) return steps;
        if(i<0 || i>=n) return INT_MAX;
        int x=INT_MAX;
        for(int j=0; j<G[i].size(); j++)
        {
            x = min(x,dfs(G, G[i][j], steps+1));
        }
        return x;
    }
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++)
            indicesOfValue[arr[i]].push_back(i);
        vector<bool> visited(n); visited[0] = true;
        queue<int> q; q.push(0);
        int step = 0;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int i = q.front(); q.pop();
                if (i == n - 1) return step; // Reached to last index
                vector<int>& next = indicesOfValue[arr[i]];
                next.push_back(i - 1); next.push_back(i + 1);
                for (int j : next) {
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear(); // avoid later lookup indicesOfValue arr[i]
            }
            step++;
        }
        return 0;
        
    }
};