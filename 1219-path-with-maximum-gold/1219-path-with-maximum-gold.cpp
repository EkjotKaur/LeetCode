class Solution {
    int m, n;
    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)
            return 0;
        
        int ans = grid[i][j];
        int x = ans;
        grid[i][j]=0;
        
        ans += max(max(solve(grid, i-1, j), solve(grid, i, j-1)),max(solve(grid, i, j+1), solve(grid, i+1, j)));
        grid[i][j]=x;
        return ans;
        
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]!=0)
                    ans=max(ans, solve(grid, i, j));
            }
        }
        
        return ans;
    }
};