class Solution {
    int n, m;
    int solve(vector<vector<int>>& grid, int i, int j, int k, vector<vector<vector<int>>>&B)
    {
        if(k>=n) return 0;
        int ans=0;
        // cout<<i<<j<<" ";
        if(i<0 || j<0 || i>=m || j>=m) return 0;
        if(B[k][i][j]!=-1) return B[k][i][j];
        if(i!=j)
            ans+=grid[k][i]+grid[k][j];
        else
            ans+=grid[k][i];

        int A=0;
        for(int ii=-1; ii<=1; ii++)
        {
            for(int jj=-1; jj<=1; jj++)
                A=max(A, solve(grid, i+ii, j+jj, k+1, B));
        }
        
        B[k][i][j] = ans+A;
        return B[k][i][j];
            
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>>A(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(grid, 0, m-1, 0, A);
    }
};