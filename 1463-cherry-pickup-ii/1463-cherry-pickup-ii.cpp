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
        // cout<<ans<<" ";
        
        vector<int>A(9);
        A[0] = solve(grid, i, j, k+1, B);
        A[1] = solve(grid, i-1, j, k+1, B);
        A[2] = solve(grid, i+1, j, k+1, B);
        A[3] = solve(grid, i, j-1, k+1, B);
        A[4] = solve(grid, i-1, j-1, k+1, B);
        A[5] = solve(grid, i+1, j-1, k+1, B);
        A[6] = solve(grid, i, j+1, k+1, B);
        A[7] = solve(grid, i-1, j+1, k+1, B);
        A[8] = solve(grid, i+1, j+1, k+1, B);
        
        sort(A.begin(), A.end());
        
        // cout<<A[8]<<"   ";
        B[k][i][j] = ans+A[8];
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