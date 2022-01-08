class Solution {
    int m,n;
    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i >= m) return j;
        if(j<0 || j>=n) return -1;
        
        if(grid[i][j]==1 && (j==n-1 || grid[i][j+1]==-1)) return -1;
        if(grid[i][j]==-1 && (j==0 || grid[i][j-1]==1)) return -1;
        
        int x = solve(grid, i+1, j+grid[i][j]);
        return x;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        vector<int>A(n);
        
        for(int i=0; i<n; i++)
            A[i] = solve(grid, 0, i);
        
        return A;
    }
};