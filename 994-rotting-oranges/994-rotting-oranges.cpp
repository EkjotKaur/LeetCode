class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<vector<int>>Q;
        
        int n=grid.size(), m=grid[0].size(),c=0, t=0;
       
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    Q.push({i,j,0});
                }
                else if(grid[i][j]==1) c++;
            }
        }
        
        while(!Q.empty())
        {
            int i=Q.front()[0];
            int j=Q.front()[1];
            int time = Q.front()[2];
            int x = c;
            Q.pop();
            t=time;
            if(i!=0 && grid[i-1][j]==1)
            {
                c--;
                grid[i-1][j]=2;
                Q.push({i-1, j, time+1});
            }
            if(j!=0 && grid[i][j-1]==1)
            {
                c--;
                grid[i][j-1]=2;
                Q.push({i, j-1, time+1});
            }
            if(i!=n-1 && grid[i+1][j]==1)
            {
                c--;
                grid[i+1][j]=2;
                Q.push({i+1, j, time+1});
            }
            if(j!=m-1 && grid[i][j+1]==1)
            {
                c--;
                grid[i][j+1]=2;
                Q.push({i, j+1, time+1});
            }
        }
        
        if(c>0) return -1;
        return t;
    }
};